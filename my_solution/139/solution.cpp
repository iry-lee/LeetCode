// 可以用递归求解
// 递归求解超时，原因自然也是很多子问题被重复计算了
// 例如测试样例："aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab"
// ["a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"]
// 解决这一问题，需要用到的就是动态规划DP
class Solution {
public:
    void func(string s, int begin, vector<string> & wordDict, bool *dp){
        s = s.substr(begin);
        bool flag = false;
        for(auto word : wordDict){
            bool t = true;
            for(int i = 0, j = 0; i < word.size(); i++, j++){
                if(j == (int)s.size() || word[i] != s[j]) {
                    t = false;
                    break;
                }
            }
            int len = word.size();
            if(t) flag = dp[begin+len];
            if(flag) break;
        }
        dp[begin] = flag;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        bool dp[n+1];
        memset(dp, false, sizeof(dp));
        dp[n] = true;
        for(int i = n-1; i >= 0; i--)
            func(s, i, wordDict, dp);
        return dp[0];
    }  
};
// 总的来说，这不算是一道比较难的动态规划题
// 建立起来数组保存子问题的解以后，就可以解决