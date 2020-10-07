// 最优解，官方解法三
// 这里对下面的方法做了一点小修改，之前是覆盖，这里改为了交换
// 最坏时间时间复杂度与下面的方法相同，但是在0比较多的时候更加快一些
// 主要的思路很简单，就是如果是非0的话就换到前面去
// 这时候如果前面有非0元素就不会被换到前面，直到被ptr指针遇到以后被换到后面去，直到被换到了最后面
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int ptr = 0;
        for(int i = 0; i < (int)nums.size(); i++){
            if(nums[i] != 0){
                if(ptr != i) swap(nums[ptr], nums[i]);
                ptr++;
            }
        }
    }
};

// 我的方法相当于是双指针，官方解法二
// class Solution {
// public:
//     void moveZeroes(vector<int>& nums) {
//         int ptr = 0;    // ctZero存储已经遍历到的0的个数，ptr记录非0元素覆盖到位置
//         for(int i = 0; i < (int)nums.size(); i++){
//             if(nums[i] != 0){
//                 if(i > ptr) nums[ptr] = nums[i];
//                 ptr++;
//             }
//         }
//         // for(int i = ptr; i < (int)nums.size(); i++) nums[i] = 0;
//     }
// };