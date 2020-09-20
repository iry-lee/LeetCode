// 题目的测试点，不一定有序
class Solution {
public:
    static bool comp(const vector<int> &a, const vector<int> &b){
        return a[0] < b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        int i = 0;
        if(intervals.empty()) return res;
        // 排序
        sort(intervals.begin(), intervals.end(), comp);
        res.push_back(intervals[i++]);
        for( ; i < intervals.size(); i++){
            if(intervals[i][0] <= res[res.size()-1][1])
                res[res.size()-1][1] = max(intervals[i][1], res[res.size()-1][1]);
            else res.push_back(intervals[i]);
        }
        return res;
    }
};