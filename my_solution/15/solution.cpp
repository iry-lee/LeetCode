//
// Created by 11029 on 2020/6/12.
//
// 首先这个题可以使用暴力解法，这样的话时间复杂度就是O(n^3)
// 此时想到了之前的那个双指针的方法。这个题是不是可以每次先固定一个，然后使用双指针？
// 这样复杂度就是O(n^2 + nlogn) = O(n^2)
// 之前的第11题就是双指针，刚做过去没多久，这次很高兴自己想起来了这种做法。
//

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> output;
        if(nums.size() < 3)
            return output;
        sort(nums.begin(), nums.end());  //O(nlogn)
        // 此为测试专用
        // output.push_back(nums);
        for(int i = 0; i < nums.size() - 2; i++){
            if(i > 0){  // 为了提前去掉重复的结果
                while(i < nums.size() && nums[i-1] == nums[i]){
                    i++;
                }
            }
            int a;
            if(i < nums.size())
                a = nums[i];
            else
                return output;
            int j = i + 1, k = nums.size() - 1;
            while(j < k){
                int b = nums[j], c = nums[k];
                if(a + b + c == 0){
                    output.push_back({a, b, c});
                    j++;
                    while(j < nums.size() && nums[j] == nums[j-1]){
                        j++;
                    }
                    k--;
                    while(k > 0 && nums[k] == nums[k+1]){
                        k--;
                    }
                }
                else if(a + b + c < 0){
                    j++;
                }
                else{
                    k--;
                }
            }
        }
        return output;
    }
};


// 看到一个思路跟我相同的做法，但他做的代码就很简洁，向人家学习啊
//
//class Solution {
//public:
//    vector<vector<int>> threeSum(vector<int>& nums) {
//        sort(nums.begin(), nums.end());
//        vector<vector<int>> output;
//        for(int i = 0; i < nums.size(); ++i) {
//            int j = i+1, k = nums.size() - 1, t = nums[i];
//            while (j < k) {
//                int res = nums[j]+nums[k]+t;
//                if (res > 0) --k;
//                else if (res < 0) ++j;
//                else {
//                    output.push_back({nums[i], nums[j], nums[k]});
//                    while (j < k && nums[j] == nums[j+1]) ++j;
//                    while (j < k && nums[k] == nums[k-1]) --k;
//                    ++j; --k;
//                }
//            }
//            while (i < nums.size()-1 && nums[i] == nums[i+1]) ++i;
//        }
//
//        return output;
//    }
//};