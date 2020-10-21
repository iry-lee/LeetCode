// 【哈希加堆排】官方解答中给出的方法，然后自行实现
// 先遍历一遍数组，用哈希表存储各个数字的出现次数
// 然后将哈希表中的数据输入到堆中
// 堆是要维护一个小顶堆，每次将小顶堆中堆顶也就是最小的那个元素拿下来

class Solution {
public:
    struct newNum {
        int num;
        int freq;
    };
    bool static NewCompare(const newNum &a, const newNum &b){
        return a.freq > b.freq;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map <int, int> um;
        vector<int> ans;
        for(int n : nums){
            if(um.find(n) == um.end()) um[n] = 1;
            else um[n]++;
        }
        unordered_map<int, int>::iterator ite = um.begin();
        int ct = 0;
        vector<newNum> myHeap(k);
        while(ite != um.end()){
            if(ct < k) {
                myHeap[ct++] = {ite->first, ite->second};
                if(ct == k) make_heap(myHeap.begin(), myHeap.end(), NewCompare);
            }
            else{
                if(ite->second > myHeap[0].freq){
                    pop_heap(myHeap.begin(), myHeap.end(), NewCompare);
                    myHeap.pop_back();
                    myHeap.push_back({ite->first, ite->second});
                    push_heap(myHeap.begin(), myHeap.end(), NewCompare);
                }
            }
            ite++;
        }
        for(int i = k-1; i >= 0; i--) ans.push_back(myHeap[i].num);
        return ans;
    }
};