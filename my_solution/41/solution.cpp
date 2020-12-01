// 本题如果直接排序的话，时间复杂度为O(nlogn)，然后再遍历一遍直到遇到了缺少的整数
// 但是本题求的是，时间复杂度O(n)，空间复杂度O(1)
// 既然本题没说可能有重复数字，就是有可能有重复数组，但是应该问题不大

// [1] 我的方法：哈希
// 时间复杂度O(n)，空间复杂度O(n)的方法
// class Solution {
// public:
//     int firstMissingPositive(vector<int>& nums) {
//         vector<int> hash(nums.size(), 0);
//         int min = INT_MAX, n = nums.size();
//         for(int i : nums)
//             if(i < min && i > 0) min = i;
//         // 如果正整数最小值比1还大，那就缺1
//         if(min > 1) return 1;
//         for(int i : nums)
//             if(i > 0 && i - min < n) hash[i-min] = 1;
//         for(int j = 0; j < n; j++)
//             if(hash[j] == 0) return min+j;
//         return min+n;
//     }
// };


// [2] 我的方法：与题解中的置换方法相似
// 时间复杂度O(n)，空间复杂度O(1)的方法
// 空间复杂度为O(1)可能需要在原数组上进行操作
// 先找到最小的正数，然后把这个正数放到数组的头上，做一个记录
// class Solution {
// public:
//     int firstMissingPositive(vector<int>& nums) {
//         int n = nums.size();
//         // 用数组下标0~n-1来映射1~n
//         // 如果这个数字出现了，就将其赋值为-1，没出现则赋值为0
//         for(int i = 0; i < n; i++) if(nums[i] < 0) nums[i] = 0;
//         for(int i = 0; i < n; i++)
//             if(nums[i] > 0){
//                 if(nums[i]-1 == i) nums[i] = -1;
//                 else{
//                     int temp = nums[i]-1;
//                     if(temp < n && nums[temp] != -1){
//                         nums[i] = nums[temp];
//                         nums[temp] = -1;
//                         i--;
//                     }
//                 }
//             }
//         for(int i = 0; i < n; i++) if(nums[i] != -1) return i+1;
//         return n+1;
//     }
// };

// [3] 题解中的方法：空间复杂度为O(1)的哈希
// 又叫原地哈希
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        // 先把范围在(-infi, 0] 和 [n+1, +infi) 区间内的值都改为 n+1;
        for(int i = 0; i < nums.size(); i++)
            if(nums[i] >= n+1 || nums[i] <= 0) nums[i] = n+1;
        // for(int num : nums) cout << num << " ";
        // cout << endl;
        // 这样整个数组就都是正数了
        for(int i = 0; i < nums.size(); i++){
            if(abs(nums[i]) != n+1){
                int temp = abs(nums[i]);
                if(nums[temp - 1] > 0) nums[temp-1] *= -1;
            }
        }
        // for(int num : nums) cout << num << " ";
        // cout << endl;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > 0) return i+1;
        }
        return n + 1;
    }
};