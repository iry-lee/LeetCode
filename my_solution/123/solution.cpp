// 依旧是按照之前121、122的思路往下走
// 大概相当于对于121题，只买卖一次股票这个步骤执行两次
// 先求只买卖一次得到的各个收益，然后再在此后的时间内再只买卖一次
// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int  ans = 0, len = prices.size();
//         if(len == 0) return ans;

//         int dp[len][2][2];              // 第一个2指的是买卖两次
//         dp[0][0][0] = 0-prices[0];      // 持有股票
//         dp[0][0][1] = 0;                // 不持有股票

//         for(int i = 1; i < len; i++){
//             dp[i][0][0] = max(dp[i-1][0][0], 0 - prices[i]);
//             dp[i][0][1] = max(dp[i-1][0][1], dp[i-1][0][0] + prices[i]);
//             // 这个时候，第一次买卖的最大收益保存在了dp[i][1]
//             int tempmax = 0;
//             for(int j = i; j < len; j++){
//                 // 第二次交易开始前的状态比较重要，这里可能还有问题  =======================
//                 if(j == i){
//                     dp[i][1][0] = INT_MIN;
//                     dp[i][1][1] = 0;
//                     continue;
//                 }
//                 dp[j][1][0] = max(dp[j-1][1][0], 0 - prices[j]);
//                 dp[j][1][1] = max(dp[j-1][1][1], dp[j-1][1][0] + prices[j]);
//                 if(dp[j][1][1] > tempmax) tempmax = dp[j][1][1];
//             }
//             if(tempmax + dp[i][0][1] > ans) ans = tempmax + dp[i][0][1];
//         }
//         return ans;
//     }
// };

// 上述方法能够得到想要的解，但是时间复杂度为O(n^2)的解，并不是最优的解，因为我上面又用了一步穷举
// 改进后的方法
// 还是要回到状态转移图上来
// 这里可以直接穷举出来五个状态：
// 0. 空仓
// 1. 持有
// 2. 再空仓
// 3. 再持有
// 4. 卖出结束 这一步可以不用单独记录下来

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if(len == 0) return 0;
        
        int dp[len][4];
        // 初始化状态
        dp[0][0] = 0 - prices[0];   // 持有
        dp[0][1] = 0;               // 空仓
        dp[0][2] = 0 - prices[0];   // 再持有。 ！！！！！！这里需要注意，再持有的时候，不能初始化为0
        dp[0][3] = 0;               // 再空仓
        // 开始后续的状态转移
        for(int i = 1; i < len; i++){
            dp[i][0] = max(dp[i-1][0], 0 - prices[i]);
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] + prices[i]);
            dp[i][2] = max(dp[i-1][2], dp[i-1][1] - prices[i]);
            dp[i][3] = max(dp[i-1][3], dp[i-1][2] + prices[i]);
        }
        // for(int i = 0; i < len; i++) cout << dp[i][0] << " ";
        // cout << endl;
        // for(int i = 0; i < len; i++) cout << dp[i][1] << " ";
        // cout << endl;
        // for(int i = 0; i < len; i++) cout << dp[i][2] << " ";
        // cout << endl;
        // for(int i = 0; i < len; i++) cout << dp[i][3] << " ";
        // cout << endl;
        return dp[len-1][3];
    }
};

// 需要注意的是，这里是说最多k次，所以再持有的时候的初始化为 0 - prices[0]
// 这样的话，如果只买卖一次就能得到最优解的话，最优解也在dp[len-1][3]上得到
// 最后就是空间复杂度可以做一个优化，因为很简单，这里就不再优化了
