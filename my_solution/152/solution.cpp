// 这个题对我来说有点难，官方解答看的也有点不太明白

// 官方解答，使用动态规划，维护一个最小值一个最大值
// 
class Solution {
public:
    int maxProduct(vector<int> & nums) {
        int maxF = nums[0], minF = nums[0], ans = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            int mx = maxF, mn = minF;
            maxF = max(mx * nums[i], max(nums[i], mn * nums[i]));
            minF = min(mn * nums[i], min(nums[i], mx * nums[i]));
            ans = max(maxF, ans);
        }
        return ans;
    }
};

// 需要注意的是0和负数
// 如果遇到0，直接可以从0的下一个开始重新计算区间了
// 如果乘出一个负数，也不能舍弃，万一后面还有新的负数
// 所以还要求一个绝对值的乘积最大的情况，在这个情况下，并保存一下正负，每次转正为负，都可以最优解比较一下
// 这个题的解法是，动态规划？
// class Solution {
// public:
//     int maxProduct(vector<int>& nums) {
//         int max = INT_MIN, absMax = 0, absSymbol = 1, tempMax = 0;
//         for(auto i : nums){
//             if(i == 0){
//                 absMax = 0;
//                 tempMax = 0;
//                 absSymbol = 1;
//                 if(tempMax > max) max = tempMax;
//             }
//             else if(i > 0){
//                 if(tempMax <= 0) tempMax = i;
//                 else tempMax *= i;
//                 if(absMax == 0) absMax = i;
//                 else absMax *= i;
//                 if(tempMax > max) max = tempMax;
//                 if(absMax > max && absSymbol == 1) max = absMax;
//             }
//             else{   // 为负数
//                 tempMax = i;
//                 if(tempMax > max) max = tempMax;
//                 if(absMax == 0){
//                     absMax = -1*i;
//                     absSymbol = -1;
//                 }
//                 else{
//                     absMax *= (-1*i);
//                     absSymbol *= -1;
//                 }
//                 if(absMax > max && absSymbol == 1) max = absMax;
//             }
//         }
//         return max;
//     }
// };
// 上述方法行不通，出错的测试点： [2,-5,-2,-4,3]
// 上面的方法难以解决上述样例的问题，三个负数连在一起，到底应该选哪两个？