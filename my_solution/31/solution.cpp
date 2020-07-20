class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // 最大的数是全逆序，最小的数是全顺序
        // 所以是不是顺序变逆序会带动其字典序的上升
        // 找到最后的一个顺序对(i-1,i)
        // 然后在[i, end)之中也是从后往前遍历，找到第一个大于A[i-1]的数字A[k]
        // 交换A[i-1]与A[k]，然后让[i,end)转为升序。
        bool flag = true;
        for(int i = nums.size()-1; i > 0; i--){
            if(nums[i] > nums[i-1]){
                int k = 0;
                for(k = nums.size()-1; k >= i; k--) if(nums[k] > nums[i-1]) break;
                int temp = nums[k];
                nums[k] = nums[i-1];
                nums[i-1] = temp;
                // 把[i, end)转为升序
                for(int j = i; j < (nums.size() + i)/2; j++){
                    int temp = nums[j];
                    nums[j] = nums[nums.size()-1-j+i];
                    nums[nums.size()-1-j+i] = temp;
                }
                flag = false;
                break;
            }
        }
        // 如果全是逆序数的话，就把其头尾两两交换转成正序数
        if(flag){
            for(int i = 0; i < nums.size()/2; i++){
                int temp = nums[i];
                nums[i] = nums[nums.size()-1-i];
                nums[nums.size()-1-i] = temp;
            }
        }
    }
};

// main.cpp
//#include <iostream>
//#include <cstdio>
//#include "utils.h"
//# include "my_solution/31/solution.cpp"   // 这里如果想跑哪一个题目的话，只要把中间的那个题号改掉就可以了
//
//int main() {
//
//    Solution solution;  // 实例化题解文件中的类
//
//    vector<int> input = utils::getVector();
//    solution.nextPermutation(input);
//
//    return 0;
//}