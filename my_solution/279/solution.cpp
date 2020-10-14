class Solution {
public:
    int numSquares(int n) {
        // 建立一个dp数组，把从1到n-1的结果存下来，dp[i]中存放的是i+1的完全平方数的个数
        int dp[n];
        dp[0] = 1;
        for(int i = 1; i < n; i++){
            int number = i + 1;
            int numbersqrt = sqrt(number);
            if(numbersqrt*numbersqrt == number) dp[i] = 1;
            else{
                dp[i] = INT_MAX;
                for(int j = 0; j <= i/2; j++)
                    if(dp[j] + dp[i-1-j] < dp[i]) dp[i] = dp[j] + dp[i-1-j];
            }
        }
        return dp[n-1];
    }
};