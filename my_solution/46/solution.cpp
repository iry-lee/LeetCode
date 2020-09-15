// 官方的思路
// 回溯 + 交换
class Solution {
public:
    void addBack(vector<vector<int>>& res, vector<int> nums, int first){
        if(first == (int)nums.size()-1){
            res.push_back(nums);
        }
        else{
            for(int i = first; i < nums.size(); i++){
                // 这一部分还可以再优化，不用复制vector，用两次swap就可以了
                // vector<int> temp = nums;
                // int t = temp[i];
                // temp[i] = temp[first];
                // temp[first] = t;
                swap(nums[i], nums[first]);   // 先swap
                addBack(res, nums, first+1);
                swap(nums[i], nums[first]);   // 再swap回来
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size() > 0) addBack(res, nums, 0);
        return res;
    }
};


// 改用深度优先遍历
// 深度优先+回溯是这个题目较优的解法
// 所以，使用深度优先的话，返回的参数类型是 vector<vector<int>>
// class Solution{
// public:
//     vector<vector<int>> permute(vector<int>& nums) {
//         vector<vector<int>> res;
//         if(nums.size() == 0) return res;
//         else if(nums.size() == 1){
//             vector<int> temp;
//             temp.push_back(nums[0]);
//             res.push_back(temp);
//             return res;
//         }
//         for(int i = 0; i < nums.size(); i++){
//             vector<int> subnums;
//             for(int j = 0; j < nums.size(); j++){
//                 if(j == i) continue;
//                 else subnums.push_back(nums[j]);
//             }
//             vector<vector<int>> temp = permute(subnums);
//             for(auto v : temp){
//                 v.push_back(nums[i]);
//                 res.push_back(v);
//             }
//         }
//         return res;
//     }
// };


// 我使用的是广度优先遍历，是一个不太好的解法
// 广度优先遍历的耗费的空间大，期间为了保存数据也耗费了很多资源，但是不用回溯
// class Solution {
// public:
//     void func(vector<vector<int>>& res, vector<int> choose, vector<int> v){
//         if(choose.size() == 0) res.push_back(v);
//         else{
//             for(int i = 0; i < choose.size(); i++){
//                 vector<int>temp, temp2(v);
//                 for(int j = 0; j < choose.size(); j++){
//                     if(j == i) continue;
//                     else{
//                         temp.push_back(choose[j]);
//                     }
//                 }
//                 temp2.push_back(choose[i]);
//                 func(res, temp, temp2);
//             }
//         }
//     }
//     vector<vector<int>> permute(vector<int>& nums) {
//         vector<vector<int>> res;
//         vector<int> init;
//         func(res, nums, init);
//         return res;
//     }
// };