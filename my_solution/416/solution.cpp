// 题目给出数组大小不超过200，说明这个问题的时间复杂度是不低的
// 是不是可以通过交换数组中的元素，然后找到一个分界，界线的左边元素和右边元素的和相同
// 类似于partition算法？
// 或者先求和，分成的两个数组，一个有全部的元素，一个不含任何元素
// 然后通过通过将元素移动到空数组中，来调整，从而使得两个数组的之和相等
// 如果存在一个数，它的大小比其他的数的总和还要大，或者它超过全部数字总和的一半，那么就false
// 除此之外呢？
// 再怎么把数字分配到两个数组中？
// 实在是没有思路。看了一下题解
// 本题依旧是一个动态规划题，本题等价于->从一个数组中选出几个数字，使这几个数字的总和恰好等于数组总和一半
// 就与0-1背包问题有点相似
// 相似题目，Leetcode-40 组合总和II
// 此外几种显而易见的false情况可以提前排除一下
// 使用动态规划，如何从原问题得到原问题的子问题，然后再如何通过子问题的解得到原问题的解?
// 原问题：从一个大小为n(n>=2)，总和为sum的数组中，找出m个数字，使得这m个数字的和为sum/2。
//      假如当前数字的之和为k，dp[k] = dp[k-num] + num
//      那么每个状态dp应该是由一个数组以及这个数组的和组成，数组中存放的是不在这个数组中的数字
//      
// 【dfs求解】
// 运行超时，正确性应该没有问题
/*
class Solution {
public:
    bool func(vector<int>& candidates, int begin, int target){
        // 把begin及此后出现的数字存在hash中
        // hashmap中存放的是数值和它的开始位置
        unordered_map<int, int> hashmap;
        for(int i = begin; i < candidates.size(); i++){
            // cout << i << endl;
            if(hashmap.find(candidates[i]) == hashmap.end())
                hashmap[candidates[i]] = i;
        }
        unordered_map<int, int>::iterator ite = hashmap.begin();
        for( ; ite != hashmap.end(); ite++){
            // cout << ite->first << ": " << ite->second << endl;
            if(target == ite->first){
                vector<int> temp(1, ite->first);
                return true;
            }
            else if(target >= 2 * ite->first) {
                // 因为排过序，这里可以做一下剪枝，
                // 如果target - ite->first < ite->first也不行
                bool subans = func(candidates, ite->second + 1, target - ite->first);
                if(subans) return subans;
            }
        }
        return false;
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0, n = nums.size();
        // 如果nums大小为0，则返回true
        if(n == 0) return true;
        for(auto n : nums) sum += n;
        // 如果总和为奇数，则不行
        if(sum % 2 == 1) return false;
        sort(nums.begin(), nums.end());
        // 如果最大值比sum的一半还大，也不行；如果刚好等于sum的一半，显然可以
        if(nums[(int)nums.size()-1] > sum/2) return false;
        else if(nums[(int)nums.size()-1] == sum/2) return true;
        else return func(nums, 0, sum/2);
    }
};*/

// 自己想到的动态规划的方法
// 刚好不超时
// dp用unordered_set存储，只存储和的大小
// 先对nums排序
/*
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        unordered_set<int> hash;
        int sum = 0, n = nums.size();
        if(n == 0) return true;
        sort(nums.begin(), nums.end());
        for(int n : nums) sum += n;
        if(sum % 2 == 1) return false;
        if(nums[n-1] > sum / 2) return false;
        else if(nums[n-1] == sum / 2) return true;
        for(int n : nums){
            // 遍历一遍集合
            unordered_set<int> tempHash = hash;
            unordered_set<int>::iterator ite = hash.begin();
            // 哈希的复杂度在于遍历而不是查找
            for( ; ite != hash.end(); ite++){
                int temp = *ite + n;
                if(temp > sum / 2) continue;    // 这个剪枝为啥效果不明显？
                if(temp == sum/2) return true;
                if(tempHash.find(temp) == tempHash.end())
                    tempHash.insert(temp);
            }
            hash = tempHash;
            if(hash.find(n) == hash.end()) hash.insert(n);
        }
        return false;
    }
};*/
// 官方解法：二维动态数组
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0, n = nums.size(), target;
        // 预处理，解决一些显而易见的不可能的情况
        if(n == 0) return true;
        sort(nums.begin(), nums.end());
        for(int n : nums) sum += n;
        target = sum/2;
        if(sum % 2 == 1) return false;
        if(nums[n-1] > target) return false;
        else if(nums[n-1] == target) return true;
        // 建立dp数组,dp[i][j]表示，在数组下标[0,i]的范围内，是否存在一个子数组满足其和为j。
        int dp[n][target+1];
        memset(dp, 0, sizeof(dp));
        // 初始化一些边界条件
        dp[0][nums[0]] = 1; // 当i==0的时候，只有nums[0]为1
        for(int i = 1; i < n; i++){
            dp[i][0] = 1;   // 即啥都不取，所以dp[i][0]显然为1
            for(int j = 0; j < target+1; j++){
                if(dp[i-1][j] == 1){
                    dp[i][j] = 1;
                    if(j + nums[i] < target + 1) dp[i][j + nums[i]] = 1;
                }
            }
        }
        return dp[n-1][target];
    }
};