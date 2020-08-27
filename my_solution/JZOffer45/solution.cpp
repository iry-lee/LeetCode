// 拼接得到的数字，位数是固定的，甚至前导0也不需要去掉
// 可以设置一个大小比较的规则，然后根据这一规则对nums中值进行排序
// 排好序以后拼接起来就能得到结果
// 但下面我的方法会爆栈，可能是因为被sort调用的原因？
class Solution {
private:
    bool static comp(string s1, string s2){
        if(s1.size() < s2.size()){
            int d = s2.size() - s1.size();
            s1.append(d, s1[s1.size()-1]);
        }
        else if(s2.size() < s1.size()){
            int d = s1.size() - s2.size();
            s2.append(d, s2[s2.size()-1]);
        }
        return s1 <= s2;
    }
public:
    // a <= b 返回 true，其他情况返回false
    string minNumber(vector<int>& nums) {
        vector<string> str;
        string result;
        for(int i = 0; i < nums.size(); i++){
            str.push_back(to_string(nums[i]));
        }
        sort(str.begin(), str.end(), comp);
        for(int i = 0; i < str.size(); i++){
            result += str[i];
        }
        return result;
    }
};

// 这个 @北冥有鱼 的做法跟我思路一样，但是下面的那个测试点跑起来没有问题
// class Solution {
// public:
//     string minNumber(vector<int>& nums) {
//         vector<string> strs;
//         string res;
//         for(auto num:nums)
//             strs.push_back(to_string(num));
//         sort(strs.begin(),strs.end(),compare);
//         for(auto str:strs)
//             res+=str;
//         return res;
//     }
// private:
//     static bool compare(const string &a,const string &b)
//     {
//         return a+b<b+a;
//     }
// };

// 跑这个测试点会爆栈：
// [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]