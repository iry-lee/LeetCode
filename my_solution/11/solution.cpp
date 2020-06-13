//
// LeetCode-11题
//
// 首先尝试了一下暴力求解，发现O(n^2)的时间复杂度会超时，说明题目还是有运行的时间限制
//
//int maxArea(vector<int>& height) {
//    int max = 0;
//    for(int i = 0; i < height.size(); i++){
//        for(int j = i+1; j < height.size(); j++){
//            int area = (j-i)*min(height[i], height[j]);
//            if (area > max) max = area;
//        }
//    }
//    return max;
//}
//
// 那么，可能的时间复杂度更好的解法应该是至少为O(n)或者O(nlogn)
// 于是发现，最高的那根柱子一定会接触水，得到一种特殊情况下是O(n)，普通情况下是O(nlogn)的方法
// 但我下面的这个方法仍旧是O(n^2)。
//
//#include <unordered_map>
//
//class Solution {
//public:
//    int maxArea(vector<int>& height) {
//        int _max = 0, H = 0, Hmax = 0;
//        for(int i = 0; i < height.size(); i++){
//            if(height[i] > Hmax){
//                Hmax = height[i];
//                H = i;
//            }
//        }
//        // 得到了最高的柱子的高度以及其所在的位置
//        if(H == 0){
//            for(int i = 1; i < height.size(); i++){
//                int area = (i-H)*height[i];
//                if(area > _max)
//                    _max = area;
//            }
//        }
//        else if(H == height.size()-1){
//            for(int i = 0; i < height.size()-1; i++){
//                int area = (H - i)*height[i];
//                if(area > _max)
//                    _max = area;
//            }
//        }
//        else{
//            //分别求左右的最高水量和对应的水位
//            //真正的最高水量的水位应该是在左右的最高水量时的水位之中出现？
//            int L = 0, left_max = 0, R = 0, right_max = 0;
//            for(int i = 0; i < H; i++){
//                int left_area = (H - i)*height[i];
//                if(left_area > left_max || (left_area == left_max && height[i] > height[L])){
//                    L = i;
//                    left_max = left_area;
//                }
//            }
//            for(int i = H + 1; i < height.size(); i++){
//                int right_area = (i-H)*height[i];
//                if(right_area > right_max || (right_area == right_max && height[i] > height[R])){
//                    R = i;
//                    right_max = right_area;
//                }
//            }
//            //最优的水位将出现在height[L]与height[R]之间
//            std::unordered_map<int,int> hash;
//            vector<int> temp;
//            int hmin = min(height[L], height[R]);
//            int hmax = max(height[L], height[R]);
//            for(int & i : height){
//                if(i >= hmin && i <= hmax){
//                    if(hash.find(i) == hash.end()){
//                        temp.push_back(i);
//                        hash.insert(std::make_pair(i, i));
//                    }
//                }
//            }
//            for(int i = 0 ; i < temp.size(); i++){
//                int level = temp[i];
//                int begin = 0, end = 0;
//                for(int j = 0; j < height.size(); j++){
//                    if(height[j] >= level){
//                        begin = j;
//                        break;
//                    }
//                }
//                for(int j = height.size()-1; j >= 0; j--){
//                    if(height[j] >= level){
//                        end = j;
//                        break;
//                    }
//                }
//                int area = (end - begin) * level;
//                if(area > _max)
//                    _max = area;
//            }
//        }
//        return _max;
//    }
//};
//
// 最终上面的方式过了，而且耗时也还好，可能是因为它测耗时的那个点刚好就被我的O(n)的情况给覆盖了
// 最后看了看题解才懂得双指针的方法。确实巧妙。之前又想到，但是没有想清楚指针移动的方式和交换的方式。
//
// 【双指针法】
// 如果使用暴力解法，时间复杂度为O(n^2)。但是这种方法计算了所有的两条边的情况，而其中很多情况都是可以排除掉的。
// 双指针的方法就是这么给出的。它主要的思路是，先确定一个左指针一个右指针，分别指向数组的头和尾。
// 然后不断移动左右指针，直到重合，在这个过程中，所有可能的情况面积最大的就是最优解。
// 看到这里很多人都会有一个疑问，为什么可以减少这么多计算次数，又能保证得到的结果是正确的呢？
// 这里就要关注到指针是如何变化的，以及面积的公式：
// area = |i - j| * min(height[i], height[j])，面积与短边以及两边间域有关。
// 每次，移动左右指针中的一个，而且左指针只能往右移动，右指针只能往左移动。
// 每次移动的都是指针指向的边中较短的那个的指针。假设有一个左指针l和右指针r。
// 如果height[l] < height[r]，那么无论如何往左移动右指针r，其短边的高度都不会比当前更高，间距只会缩小，
// 所以其得到的面积都不会比当前的面积大。
// 从而，每次移动短边就可以完全地将许多不可能的解筛掉，从而提高了效率。
//

class Solution {
public:
    int maxArea(vector<int> &height) {
        int leftP = 0, rightP = (int)height.size()-1;
        int maximum = 0;
        while(leftP < rightP){
            int area = (rightP - leftP) * min(height[rightP], height[leftP]);
            if(area > maximum) maximum = area;
            if(height[leftP] < height[rightP]) leftP++;
            else rightP--;
        }
        return maximum;
    }
};

//
//【一点点感想】：
//其实对算法的改进，很多时候是要考虑如何将问题的规模不断缩减，比如常用的分而治之。
//之前在面试的时候遇到过这道题，当时也是做的一塌糊涂，一时也没想到这个双指针的方法。
//这次在看答案之前也一直没有想到这个方法，自己一直在想办法降问题的规模。想着降到O(nlogn)。
//而这个题的trick在于，它是使用数学知识也好，常识推理也好，在计算过程中提前筛掉了很多之前可能会去尝试的可能的解。
//类似于剪枝，那些已经就不可能的解，就没有必要继续去算了。
//从而提高了计算效率。
