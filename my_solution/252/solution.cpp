// 排序，然后判断相邻时间段，比较上次会议的结束时间和下次会议的开始时间
class Solution {
public:
    bool static myCompare(vector<int>& a, vector<int>& b){
        return a[0] < b[0];
    }
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), myCompare);
        for(int i = 1; i < intervals.size(); i++)
            if(intervals[i-1][1] > intervals[i][0]) return false;
        return true;
    }
};