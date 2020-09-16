// 这个题在JZOffer42的时候做过，但是到了这里又忘了
// 此外，分治法也很好，有时间可以实现一下
// LeetCode上的举例分析数组规律，写成代码其实是跟下面的动态规划一样的
class Solution {
public:
    int maxSubArray(vector<int>& nums){
        int max = INT_MIN, sum = 0;
        for(int i : nums){
            if(sum < 0) sum = 0;
            sum += i;
            if(sum > max) max = sum;
        }
        return max;
    }
};

// 【动态规划】
// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         int ptr = 0, sum = 0, max_sum = INT_MIN;
//         for(int i = 0; i < nums.size(); i++){
//             if(sum < 0) sum = 0;
//             sum += nums[i];
//             if (sum > max_sum) max_sum = sum;
//         }
//         return max_sum;
//     }
// };