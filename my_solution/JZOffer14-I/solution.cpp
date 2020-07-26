#include <vector>
#include <iostream>

using namespace std;

// 动态规划类题目，最重要的是找到递推公式，然后把子问题的解求解出来以后保存下来
// 书上的做法是，f(n) = max(f(i)*f(n-i))
class Solution{
public:
    int cuttingRope(int n){
        int maxResult = 0, record [n+1];
        if(n < 2) return 0;
        if(n == 2) return 1;    // 至少切一刀，所以是1
        if(n == 3) return 2;    // 至少切一刀，所以是2

        record[0] = 0;
        record[1] = 1;      // 切0刀的时候最大
        record[2] = 2;      // 切0刀的时候最大
        record[3] = 3;      // 切0刀的时候最大

        for(int i = 4; i <= n; i++){
            int max = 0;
            for(int j = 1; j <= i/2; j++){
                if(max < record[j] * record[i-j])
                    max = record[j] * record[i-j];
            }
            // printf("%d-max: %d\n", i, max);
            record[i] = max;
        }

        maxResult = record[n];
        return maxResult;
    }
};

// 我这种方法做的其实是，在长度为n的绳子上切m刀
/*
class Solution {
public:
    int cuttingRope(int n) {
        int m = 2, maxResult = 0;
        while(m <= n){
            int max = 0;
            int recorder[m][n-m+1];
            for(int i = 0; i < m; i++){
                for(int j = 0; j < n-m+1; j++){
                    // 填充 recorder[i][j]
                    if(i == 0) recorder[0][j] = j + 1;
                    else{
                        int len = i+1+j, _max = 0;
                        for(int k = 0; k < n-m+1; k++){
                            if(i+k < len && (len-i-k) * recorder[i-1][k] > _max)
                                _max = (len-i-k) * recorder[i-1][k];
                        }
                        recorder[i][j] = _max;
                    }
                    if(i == m-1 && max < recorder[i][j]) max = recorder[i][j];
                }
            }
//            for(int i = 0; i < m; i++){
//                for(int j = 0; j < n-m+1; j++){
//                    cout << recorder[i][j] << " ";
//                }
//                cout << "\n";
//            }
            // max值应该是先递增然后递减，如果max值要递减，停止循环
            if(max > maxResult) maxResult = max;
            else break;
            m++;
        }
        return maxResult;
    }
};
*/