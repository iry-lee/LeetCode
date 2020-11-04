// 因为是一个整数数组，所以不从当前位置加到末尾，真不知道是否是一个解
// 如果要暴力求解的话，时间复杂度为O(n^2)
// 感觉这个题又要用动态规划了：
// f(i) = f(i-1) + 在[0,i-1]中，有多少个j，使[j,i]的和为k
// 从[0,i-1]加到i-1的值是可以提前求出来的，但这一过程的时间复杂度也要n
// 所以总的时间复杂度为O(n^2)较暴力法也没啥提高，提交以后发现果然超时了
// 有没有时间效率更高的动态规划？用更多的空间来换？

// 【官方解法】前缀和 + 哈希
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0, sum = 0;
        unordered_map<int, int> prefix;
        // 提前存一下
        prefix[0] = 1;
        for(int n : nums){
            sum += n;
            // 如果存在prefix + k = sum，则存在这个子数组
            int delta = sum - k;
            if(prefix.find(delta) != prefix.end()) ans += prefix[delta];
            prefix[sum]++;
        }
        return ans;
    }
};

// O(n^2)的动态规划
/*
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0;
        vector<int> dp;
        // 时间复杂度 O(n^2)
        for(int i = 0; i < nums.size(); i++){
            if(i == 0){
                if(0 == k - nums[0]) ans++;
                dp.push_back(nums[0]);
            }
            else{
                int delta = k - nums[i];
                // 时间复杂度 O(n)
                dp.push_back(0);
                for(auto d : dp) if(d == delta) ans++;
                for(int j = 0; j < dp.size(); j++) dp[j] += nums[i];
            }
        }
        return ans;
    }
};
*/