class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        if(amount == 0) return 1;
        if(n == 0) return 0;
        vector<vector<int>> dp (n, vector<int>(amount+1, 0));

        // sort(coins.begin(), coins.end());
        // base case:
        // 这里的base case有问题，因为dp[j][i]被我设置为一个累加值
        // 所以既不能全为1，也不能累加，所以就直接在循环体中做累加1这一操作了
        
        // other case:
        for(int i = 1; i <= amount; i++){
            // dp[j][i]中存的是一个累计值，累计dp[j][i]到dp[n-1][i]
            int a = 0;
            for(int j = n-1; j >= 0; j--){
                int delta = i - coins[j];
                if(delta == 0) a += 1;
                else if(delta > 0) a += dp[j][delta];
                dp[j][i] = a;
            }
        }
        return dp[0][amount];
    }
};