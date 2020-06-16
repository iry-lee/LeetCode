//
// Created by 11029 on 2020/6/12.
//
// 本题可以看作是三数之和的一个扩展

#include <algorithm>

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        if(nums.size() < 4) return result;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < (int)nums.size()-3; i++){
            int t = target - nums[i];  // 先固定住一个，t相当于是一个新的target
            for(int j = i+1; j < (int)nums.size()-2; j++){ //这里开始三数之和了
                int left = j + 1, right = nums.size()-1;
                while (left < right){
                    int tSum = nums[j] + nums[left] + nums[right];
                    if(tSum == t){
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});
                        //这里消除重复的问题
                        left++; while(left > nums.size() && nums[left] == nums[left-1]) left++;
                        right--; while(right > j && nums[right] == nums[right+1]) right--;
                    }
                    else if(tSum > t) right--;
                    else left++;
                }
                while(j + 1 < (int)nums.size()-2 && nums[j+1] == nums[j]) j++;
            }
            while(i + 1 < (int)nums.size()-3 && nums[i+1] == nums[i]) i++;
        }
        return result;
    }
};

// main.cpp文件
//
//#include <iostream>
//#include "utils.h"
//# include "my_solution/18/solution.cpp"   // 这里如果想跑哪一个题目的话，只要把中间的那个题号改掉就可以了
//
//int main() {
//    char c;
//    Solution solution;  // 实例化题解文件中的类
//
//    vector<int> input = utils::getVector();
//    int target = utils::getInt();
//    vector<vector<int>> output = solution.fourSum(input, target);
//    utils::printVector2D(output);
//
//    return 0;
//}