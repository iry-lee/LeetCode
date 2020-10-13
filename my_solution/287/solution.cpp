// 时间复杂度小于O(n^2)： 不能暴力求解
// 不能改原数组： 不能排序
// O(1)空间复杂度： 不能哈希
// 重复数字不一定只重复出现一次： 不能求和然后作差

// 所以是不是要用到下标？
// a[i]的值要么是i，要么是其他的值
// 如果是i则跳到i+1（？？？原理）
// 如果是a[i]!=i，则跳到a[a[i]]

// 数组的下标与数组中的值的对应关系确实可以提供一种解决问题的思路
// 如果数组中没有重复的元素，那么数组的值与数组的下标应该是一一对应的
// 一旦有了重复的元素，那么就有两个及以上的下标对应同一个值

// 官方题解中的二分查找法：
// 这像是一种统计方法
// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
//         int begin = 1, end = nums.size()-1;
//         while(begin < end){
//             int middle = (begin + end) / 2;
//             int ct = 0;
//             for(int i = 0; i < nums.size(); i++){
//                 if(nums[i] <= middle) ct++;
//             }
//             if(ct <= middle){
//                 begin = middle+1;
//             }
//             else{
//                 end = middle;
//             }
//         }
//         return end;
//     }
// };

// 官方解法中的二进制解法
// 略

// 官方解法中的快慢指针，又叫Floyd算法或者龟兔赛跑算法
// 思路可以参考找链表中的环
// 解释一下，为啥可以这样来做：
// 用图的视角来看待这个问题，
// 这里把每个1到n之中的数字i看成是一个图中的节点；i->nums[i]看成是图中的边
// 这也意味着，图中的节点个数 <= n，边的数量为n+1
// 所有点的出度都为1，只有一个点的入度大于1，其他点的入度都为1
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int fast = 0, slow = 0;
        bool flag = true;
        while(flag || fast != slow){
            flag = false;
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        // 慢指针回到起始位置
        slow = 0;
        while(fast != slow){
            slow = nums[slow];
            fast = nums[fast];
        }
        return fast;
    }
};
