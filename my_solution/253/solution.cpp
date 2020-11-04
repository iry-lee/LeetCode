// 【官方解答】优先级队列/最小堆
// 这个问题同样可以用来解决公交车上有多少人的问题
// 同时在一些想要使用堆来解决的问题，使用优先级队列就可以实现
class Solution {
public:
    bool static myCompare(vector<int>& a, vector<int>& b){
        return a[0] < b[0];
    }
    int minMeetingRooms(vector<vector<int>>& intervals) {
        if(intervals.size() == 0) return 0;
        sort(intervals.begin(), intervals.end(), myCompare);
        priority_queue<int, vector<int>, greater<int>> pq;
        //每次进优先级队列的是结束时间
        pq.push(intervals[0][1]);
        for(int i = 1; i < intervals.size(); i++){
            if(pq.top() <= intervals[i][0]) pq.pop();
            pq.push(intervals[i][1]);
        }
        return pq.size();
    }
};

// 有点像一个涂色问题
// 只需要某个时间段，最多重叠了几场会议就可以了吧
// 【我的方法】
// 这里我使用map来存储每个时间与会议次数的对应关系
// 对于每场会议，对应更新map中的值的时候，遍历了整个map，所以总的时间复杂度为O(n^2)
// 提交以后超时
// 【改进】
// 利用map遍历的有序性的特点对上述方法进行改进
// 将更新map中值的部分从遍历整个map改为先寻找会议时间段在map中的起止位置
// 然后更新起止位置内的元素的值，最坏时间复杂度仍为O(n^2)，但是近似时间复杂度能达到O(nlogn)
/*
class Solution {
public:
    bool static myCompare(vector<int>& a, vector<int>& b){
        return a[0] < b[0];
    }
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int max = 0;
        sort(intervals.begin(), intervals.end(), myCompare);
        // 先统计一下所有涉及到的时间节点
        // map->first是开始时间，map->second是会议数量
        map<int, int> timeMap;
        unordered_set<int> timeHash;
        // 时间复杂度O(nlogn)
        for(auto i : intervals){
            for(int j = 0; j < 2; j++)
                // 时间复杂度 O(logn)
                if(timeHash.find(i[j]) == timeHash.end()){
                    timeHash.insert(i[j]);
                    pair<int, int> value(i[j], 0);
                    timeMap.insert(value);
                }
        } 
        // 时间复杂度O(n^2) ~ 一般情况下，近似于O(nlogn)
        for(auto i : intervals){
            int begin = i[0], end = i[1];
            // 时间复杂度O(logn)
            map<int, int>::iterator bposi = timeMap.find(begin);
            map<int, int>::iterator eposi = timeMap.find(end);
            // 时间复杂度O(n) ~ 一般情况下，可能近似于O(1)
            for(; bposi != eposi; bposi++)
                if(bposi->first >= begin && bposi->first < end) bposi->second++;
        }
        map<int, int>::iterator ite = timeMap.begin();
        for(; ite != timeMap.end(); ite++)
            if(max < ite->second) max = ite->second;
        return max;
    }
};
*/