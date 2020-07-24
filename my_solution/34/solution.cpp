#include <vector>

using namespace std;

class Solution {
public:
    // head == true 表示查找的是target所处的区间的头
    // head == false 表示查找的是target所处的区间的尾
    int function(vector<int> &nums, int begin, int end, int target, bool head){
        printf("[%d, %d]\n", begin, end);
        if(begin > end) return -1;
        else if (begin == end){
            if((head && begin-1 >= 0 && nums[begin-1] < target && nums[begin] == target
                || head && begin== 0 && nums[begin] == target)
               ||(!head && begin+1 < (int)nums.size() && nums[begin+1] > target && nums[begin] == target
                  || !head && begin == (int)nums.size()-1 && nums[begin] == target))
                return begin;
            else return -1;
        }
        //处理完特殊情况以后
        int middle = (begin + end) / 2;
        int temp = function(nums, middle, middle, target, head);
        if(temp != -1) return temp;
        else{
            if(nums[middle] < target || !head && nums[middle] == target) return function(nums, middle+1, end, target, head);
            else return function(nums, begin, middle-1, target, head);
        }

    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> section;
        section.push_back(function(nums, 0, (int)nums.size()-1, target, true));
        section.push_back(function(nums, 0, (int)nums.size()-1, target, false));
        return section;
    }
};