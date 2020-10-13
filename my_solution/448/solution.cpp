// 想到LeetCode287题，重复数
// 287题的方法有：二分查找，位运算，Floyd算法
// 二分查找似乎是不太行，位运算应该也不行
// 所以用Floyd算法？
// 题目要求时间复杂度为O(n)，空间复杂度为O(1)，那就只能修改原数组了
// 好吧上面的思路是没有问题的，但是方法最后没有想出来，看了一下官方解答，确实很妙
// 能使用这一方法的条件是蛮苛刻的：数组中都是正整数、而且存在一个具体的分布范围
// 官方方法二、原地修改

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        for(int num : nums)
            if(nums[abs(num)-1] > 0) nums[abs(num)-1] *= -1;
        for(int i = 0; i < nums.size(); i++)
            if(nums[i] > 0) res.push_back(i+1);
        return res;
    }
};

// 先来个哈希，时间复杂度为O(n)，空间复杂度为O(n)
// class Solution {
// public:
//     vector<int> findDisappearedNumbers(vector<int>& nums) {
//         int n = nums.size(), hash [n+1];
//         vector<int> res;
//         memset(hash, 0, sizeof(hash));
//         for(int num : nums) hash[num]++;
//         for(int i = 1; i <= n; i++)
//             if(hash[i] == 0) res.push_back(i);
//         return res;
//     }
// };