// 0-1背包问题
// 每个元素只有取和不取两种情况
// 依次考虑strs中的元素
// 无论是取还是不取，都是在之前所有的状态下，增加自己的这个状态
// dp的大小为[strs.size()][m][n]
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int len = strs.size();
        vector<int> help (len+1, 0);
        vector<vector<int>> dp (len+1, vector<int>(m+1, -1));
        // vector<vector<vector<int>>> dp (len+1, vector<vector<int>>(m, vector<int>(n, 0)));
        // base case:
        help[0] = 1;
        dp[0][0] = 0;
        // other case:
        for(int i = 0; i < len; i++){
            // cout << "i=" << i << ", ";
            int zeroCt = 0, oneCt = 0;
            for(char c : strs[i]){
                if(c == '0') zeroCt++;
                else oneCt++;
            }
            for(int j = i; j >= 0; j--){
                if(help[j] == 1){
                    for(int k = 0; k <= m; k++){
                        if(dp[j][k] == -1) continue;
                        int zeroCtNew = zeroCt + k;
                        int oneCtNew = oneCt + dp[j][k];
                        if(zeroCtNew <= m && oneCtNew <= n &&
                                (dp[j+1][zeroCtNew] == -1 || dp[j+1][zeroCtNew] > oneCtNew)){
                            dp[j+1][zeroCtNew] = oneCtNew;
                            help[j+1] = 1;
                        }
                    }
                }
            }
            // for(int j = 0; j <= len; j++) cout << help[j] << " ";
            // cout << endl;
        }
        // 返回结果
        int res = 0;
        for(int j = 0; j <= len; j++)  if(help[j] == 1) res = j;
        return res;
    }
};