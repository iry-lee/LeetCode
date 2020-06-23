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