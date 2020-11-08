// 看题目给的例子，15前面因为没有比15还大的数字，所以15一定不包含在子数组里面
// 同样，2后面也没有比2更小的数字，所以2一定不包含在子数组里面
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        // 在数据结构中只存储下标就可以了
        int ans = nums.size(), begin = -1;
        deque <int> dq1,dq2;
        // 先从数组起始位置开始遍历，维护一个单调递增的双端队列
        for(int i = 0; i < nums.size(); i++){
            while(!dq1.empty() && nums[dq1.back()] > nums[i]) dq1.pop_back();
            dq1.push_back(i);
        } 
        // 减去左边界左边的长度
        while(!dq1.empty() && dq1.front() - begin == 1){
            begin++;
            dq1.pop_front();
            ans--;
        }
        // 如果整个数组始终有序，直接返回
        if(ans == 0) return 0;
        // 再从数组的结束位置逆向遍历，维护一个单调递减的双端队列
        for(int i = (int)nums.size()-1; i >= 0; i--){
            while(!dq2.empty() && nums[dq2.back()] < nums[i]) dq2.pop_back();
            dq2.push_back(i);
        }
        // 减去右边界右边的长度
        begin = nums.size();
        while(!dq2.empty() && begin - dq2.front() == 1){
            begin--;
            dq2.pop_front();
            ans--;
        }
        return ans;
    }
};