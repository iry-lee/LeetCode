/*
 在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，
 也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。 2 <= n <= 100000
 * */
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            int m = nums[i];
            if(i == m) continue;
            else if(nums[m] == m) return m;
            else{nums[i] = nums[m]; nums[m] = m;}
        }
        return -1;
    }
};

/*
【方法一】
 时间复杂度为O(n)，空间复杂度也为O(n)
 由于这组数字的分布范围是知道的，所以就可以设一个与当前的数组相同大小空间，然后遍历一遍，逐一把数字填进去。
    int findRepeatNumber(vector<int>& nums) {
        int bigSpace [nums.size()];
        for(int i = 0; i < nums.size(); i++){
            bigSpace[i] = 0;
        }
        for(int i = 0; i < nums.size(); i++){
            if (bigSpace[nums[i]] == 0) bigSpace[nums[i]] = 1;
            else return nums[i];
        }
        return -1;
    }
【方法二】
 时间复杂度为O(n)，空间复杂度为O(1)
 这一方法是书上的方法，相较于方法一，空间复杂度更好
 */


// main.cpp
//
//#include <iostream>
//#include <cstdio>
//#include "utils.h"
//#include "my_solution/JZOffer03/solution.cpp"   // 这里如果想跑哪一个题目的话，只要把中间的那个题号改掉就可以了
//
//int main() {
//
//    Solution solution;  // 实例化题解文件中的类
//
//    vector<int> input = utils::getVector();
//    cout << solution.findRepeatNumber(input);
//
//    return 0;
//}