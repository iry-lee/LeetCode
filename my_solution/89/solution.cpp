class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        if(n >= 0) res.push_back(0);
        if(n >= 1) res.push_back(1);
        if(n >= 2){
            for(int i = 1; i < n; i++){
                int base = 1 << i;
                int posi = base - 1;
                for(int j = 0; j < base; j++){
                    res.push_back(base+res[posi]);
                    posi--;
                }
            }
        }
        return res;
    }
};

// 为了防止重复，需要确定一个规则
// 可以规定一个状态转移的方程，
// 比如当n==1时，要遵循：
//    0 <==> 1
// 比如当n==2时，要遵循：
//    00  -->  01
//    ^        |
//    |        v
//    10  <--  11