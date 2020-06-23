//
// Created by 11029 on 2020/6/12.
//
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // j是那个快指针，i是慢指针
        int i = 0, j = 0;
        while(j < nums.size()){
            if(nums[j] == val){
                j++;
                continue;
            }
            nums[i++] = nums[j++];
        }
        for(int k = 0; k < j-i; k++){
            nums.pop_back();
        }
        return i;
    }
};

// main.cpp
//#include <iostream>
//#include "utils.h"
//# include "my_solution/27/solution.cpp"   // 这里如果想跑哪一个题目的话，只要把中间的那个题号改掉就可以了
//
//int main() {
//    char c;
//    Solution solution;  // 实例化题解文件中的类
//
//    vector<int> input = {};   //测试空数组
//    // vector<int> input = {1,1,1,1,2,2,3,4,4,4,4,5,6,6,6,7,8,9,10};  //测试普通输入
//    // vector<int> input = {1,1,1,1,1,1};   //测试全重复
//    // vector<int> input = {1,2,3,4,5,6,7,8};   //测试wuchongf
//    // vector<int> input = {0,1,1,1,1,1,1,1};
//    cout << solution.removeElement(input, 1) << "\n";
//    utils::printVector(input);
//
//    return 0;
//}