#include <vector>

using namespace std;

class Solution {
public:
    int function(vector<int> &nums, int begin, int end, int target){
        if(begin > end || begin == end && target != nums[begin]) return -1;
        else if(begin == end && target == nums[begin]) return begin;
        // 分析完了几种特殊情况
        int middle = (begin + end) / 2;
        if(nums[begin] > nums[end]){ // 说明这个区间包含旋转数组
            if(target > nums[end] && target < nums[begin]) return -1;
            if(nums[middle] > nums[end]){   // 说明begin~middle是一个顺序区间，middle+1~end是一个旋转区间
                if(nums[begin] <= target && nums[middle] >= target) return function(nums, begin, middle, target);
                else return function(nums, middle+1, end, target);
            }
            else{   // 说明middle~end是一个顺序区间，begin~middle-1是一个旋转区间
                if(nums[middle] <= target && nums[end] >= target) return function(nums, middle, end, target);
                else return function(nums, begin, middle-1, target);
            }
        }
        else{   // 说明这个区间是正常区间
            if(nums[begin] > target || nums[end] < target) return -1;
            if(nums[middle] == target) return middle;
            else if (nums[middle] > target) return function(nums, begin, middle-1, target);
            else return function(nums, middle+1, end, target);
        }
    }
    int search(vector<int>& nums, int target) {
        return function(nums, 0, nums.size()-1, target);
    }
};