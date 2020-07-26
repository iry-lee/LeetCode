#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int cuttingRope(int n) {
        int m = 2, maxResult = 0;
        while(m <= n){
//            cout << "m:" << m << "\n";
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