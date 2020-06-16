//
// Created by 11029 on 2020/6/12.
//
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