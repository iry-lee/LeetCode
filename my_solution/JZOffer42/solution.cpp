// 看到很多地方都提到了使用动态规划，想一下用动态规划怎么做
// 动态规划的核心思想是，原问题可以分解成几个子问题，通过求解子问题的最优解，可以得到原问题的最优解

// 【剑指Offer上的“举例分析数组规律”法】
// 同时其给出的动态规划方法也有如下实现，两种方法异曲同工
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ptr = 0, sum = 0, max_sum = INT_MIN;
        for(int i = 0; i < nums.size(); i++){
            if(sum < 0) sum = 0;
            sum += nums[i];
            if (sum > max_sum) max_sum = sum;
        }
        return max_sum;
    }
};