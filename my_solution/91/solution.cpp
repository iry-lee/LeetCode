class Solution {
public:
    int numDecodings(string s) {
        if(s.size() == 0) return 0;
        int dp1, dp2; // 分别表示 fn-2, fn-1
        // base case:
        dp1 = 1;
        dp2 = (s[0] >= '1' && s[0] <= '9') ? 1 : 0;
        // other case:
        for(int i = 1; i < s.size(); i++){
            int temp = 0;
            if(s[i] >= '1' && s[i] <= '9') 
                temp += dp2;
            if(s[i-1] == '1' || (s[i-1] == '2' && s[i] >= '0' && s[i] <= '6')) 
                temp += dp1;
            dp1 = dp2;
            dp2 = temp;
        }
        return dp2;
    }
};

// 看起来像是一个动态规划题
// f(n) = 0;
// 如果n这一位可以解释成一个字符，那么f(n) += f(n-1)
// 如果[n-1, n]这两位可以解释成一个字符，那么f(n) += f(n-2)