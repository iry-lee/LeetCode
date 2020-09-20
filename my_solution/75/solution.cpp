// 官方解法：一次遍历
class Solution {
public:
    void sortColors(vector<int>& nums){
        if(nums.size() == 0) return;
        int head = 0, tail = nums.size()-1;
        for(int i = 0; i < nums.size() && i <= tail; i++){
            if(nums[i] == 0){
                if(i == head) head++;
                else{
                    swap(nums[i], nums[head]);
                    i--;
                    head++;
                }
            }
            else if(nums[i] == 2){
                if(i >= tail) break;
                else{
                    swap(nums[i], nums[tail]);
                    i--;
                    tail--;
                } 
            }
        }
    }
};

// 哈希
// class Solution {
// public:
//     void sortColors(vector<int>& nums) {
//         int hash [3] = {0}, k = 0;
//         for(int i : nums){
//             hash[i]++;
//         }
//         for(int j = 0; j < nums.size(); j++){
//             if(hash[k] > 0){
//                 nums[j] = k;
//                 hash[k]--;
//             }
//             else{
//                 k++;
//                 j--;
//             }
//         }
//     }
// };