//
// Created by 11029 on 2020/6/12.
//

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        //可以设置两个指针，一个指针顺序往后遍历，另一个指针覆盖之前的数组中的值
        if(nums.size() < 1) return 0;
        int ptr1 = 1, ptr2 = 1, temp = nums[0];
        while(ptr2 < nums.size()){
            while(ptr2 < nums.size() && nums[ptr2] == temp) ptr2++;
            if(ptr2 >= nums.size()) break;
            temp = nums[ptr2];
            if(ptr1 != ptr2){
                nums[ptr1++] = nums[ptr2];
                temp = nums[ptr2++];
            }
            else{
                ptr1++;
                ptr2++;
            }
        }
        for(int i = 0; i < ptr2 - ptr1; i++) nums.pop_back();
        return ptr1;
    }
};

// main.cpp
//#include <iostream>
//#include "utils.h"
//# include "my_solution/26/solution.cpp"   // 这里如果想跑哪一个题目的话，只要把中间的那个题号改掉就可以了
//
//int main() {
//    char c;
//    Solution solution;  // 实例化题解文件中的类
//
//    // vector<int> input = {};   //测试空数组
//    // vector<int> input = {1,1,1,1,2,2,3,4,4,4,4,5,6,6,6,7,8,9,10};  //测试普通输入
//    // vector<int> input = {1,1,1,1,1,1};   //测试全重复
//    // vector<int> input = {1,2,3,4,5,6,7,8};   //测试wuchongf
//    vector<int> input = {0,1,1,1,1,1,1,1};
//    cout << solution.removeDuplicates(input) << "\n";
//    utils::printVector(input);
//
//    return 0;
//}