// 【方法一】 我想到的做k次二分查找的方法
// 最快的方式是不是时间复杂度为O(klogn)?
// 但如果k在0~n之间随机出现，那么时间复杂度就是O(nlogn)
// 循环k次二分查找，每次找的都是在某个区间内，小于当前最大值的次大值

// class Solution {
// public:
//     struct upBond{
//         int value;
//         int posi;
//     };
//     // a > b 返回true， 因为当前场景不存在a==b，否则返回false
//     bool myComp(upBond a, upBond b){
//         //cout << "a: " << a.value << ", b: " << b.value;
//         if(a.value > b.value) return true;
//         else if(a.value == b.value && a.posi >= b.posi) return true;
//         else return false;
//     }
//     upBond binarySearch(vector<int> & nums, upBond ub, int begin, int end){
//         int middle = (begin + end) / 2;
//         upBond a, b;
//         if(end - begin == 0) return {nums[end], end};
//         else if(end - begin == 1){
//             a = {nums[begin], begin};
//             b = {nums[end], end};
//         }
//         else{
//             a = binarySearch(nums, ub, begin, middle);
//             b = binarySearch(nums, ub, middle+1, end);
//         }
        
//         // a b 均不符合upBond的限制则返回一个{INT_MIN, -1}
//         if(myComp(a, ub) && myComp(b, ub)) return {INT_MIN, -1};
//         // a 不符合要求，返回b
//         else if(myComp(a, ub)) return b;
//         // b 不符合要求返回a
//         else if(myComp(b, ub)) return a;
//         // a b 都符合要求返回大的
//         else{
//             if(myComp(a, b)) return a;
//             else return b;
//         }
//         // 目前的问题是因为，这个 a<= upBond 的存在导致每次找到的都是最大值
//         // 需要记录一下每个第k大值都是被访问过的，用于区分最大值和当前值
//         // 可以增加一个带位置信息的数据结构，来存放
//         // 但是如果有三个及以上个这样的数字存在，那么就规定一个顺序：
//         // 大小相同的话，位置越靠后的越大
//         // 这里要说明一下，可能这两个值都是大于upBond，但是没办法得返回一个，后面也得继续判断
//     }
//     int findKthLargest(vector<int> & nums, int k) {
//         upBond maxBond = {INT_MAX, (int)nums.size()};
//         for(; k > 0; k--){ 
//             maxBond = binarySearch(nums, maxBond, 0, (int)nums.size()-1);
//         }
//         return maxBond.value;
//     }
// };
// 为啥这种方法最后跑完这么慢？


// 【方法二】 官方 partition方法
// 在剑指offer有这道题，但是后来又忘了这种方法
// 为啥partition算法的时间复杂度为O(n)？
// (1)
// 假设每次找到的数字都恰好位于实际顺序的中点位置，那么数组要交换一半的数字，n/2
// 然后在两个只有一半长度的数组中，选一个，再重复上述的操作，此时是n/4
// 依次类推，n/2 + n/4 + n/8 + ... + n/2^n -> n
// 所以时间复杂度是趋向于O(n)
// (2)
// 或者思考快排，在快排中，通过二分来划分问题的规模，划分成logn层，然后每层都需要比较一遍
// 每层的时间复杂度是n，所以总的时间复杂度为O(nlogn)
// 这里不要对总的排序，只做其中的一层，所以只有O(n)

class Solution {
public:
    int partition(vector<int> &nums, int begin, int end, int k){
        int n = nums.size();
        if(begin == end) return nums[begin];
        else{
            // 以nums[begin]作为标定的值
            int i = begin, j = end, l = begin;
            while(i < j){
                while(nums[i] <= nums[l] && i < l) i++;
                while(nums[j] >= nums[l] && j > l) j--;
                if(nums[i] > nums[l]){
                    swap(nums[i], nums[l]);
                    l = i;
                }
                if(nums[j] < nums[l]){
                    swap(nums[j], nums[l]);
                    l = j;
                }
            }
            // 判断一下l的值
            if(l == n-k) return nums[l];
            else if(l > n-k) return partition(nums, begin, l-1, k);
            else return partition(nums, l+1, end, k);
        }
    }
    int findKthLargest(vector<int> & nums, int k){
        int n = nums.size();
        return partition(nums, 0, n-1, k);
    }
};

// 【方法三】 我一上来就想到的方法
// 最简单的方法，先排序O(nlogn)

// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k) {
//         sort(nums.begin(), nums.end());
//         return nums[nums.size()-k];
//     }
// };