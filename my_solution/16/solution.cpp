//
// Created by 11029 on 2020/6/12.
//

// 这题跟15题很相似，应该也是使用双指针就可以
//

#include <algorithm>

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // 先排序
        sort(nums.begin(), nums.end());
        int best = 0, flag = 0;
        for(int i = 0; i < (int)(nums.size() - 2); i++){
            int j = i+1, k = nums.size()-1;
            while(j < k){
                int a = (nums[i] + nums[j] + nums[k]) - target;
                if(flag == 0){
                    best = a;
                    flag = 1;
                }
                else if(fabs(best) > fabs(a)){
                    best = a;
                }
                if(a > 0) k--;
                else if (a < 0) j++;
                else return target;
            }
        }
        return best + target;
    }
};