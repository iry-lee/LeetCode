// 题目的关键是啥？找0
// 如果整个数组都是正数，那么一定可以到达最后
// 如果有0，则从0前面的任何位置，如果都跳不到0以后的话，就说明无法到达最后一个位置

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int zeroct = 0, farest = 0, n = nums.size();
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] + i > farest) farest = nums[i] + i;
            if(nums[i] == 0 && farest <= i && i < n-1){
                return false;
            }
        }
        return true;
    }
};