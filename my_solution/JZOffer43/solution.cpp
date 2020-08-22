


// 这个题在之前的面试中有被问到过
// 当时被交给的思路是，需要把数字看成是字符串
// 比如，个位上，只有个位为1，才出现一次1，所以当 2 <= n <= 9 时，只有一个1
// 在十位上，十位为1的
// 下面这种方法还是做麻烦了
class Solution {
public:
    int countDigitOne(int n) {
        if(n == 0) return 0;
        int result = 0;
        string snumber = to_string(n);
        int statis [snumber.size()];
        int TenPowerArr[snumber.size()];
        // statis[i] 表示在第i位以及之前位都为9的时候，其中有多少个1
        // statis[0] = 0
        // 求 [1,10) 之间有几个1，就返回statis[1]
        // 求 [1, 100) 之间有几个1，就返回statis[2]
        // 以此类推...
        statis[0] = 0;
        TenPowerArr[0] = 1;
        for(int i = 1; i < snumber.size(); i++){
            statis[i] = TenPowerArr[i-1] + 10*statis[i-1];
            TenPowerArr[i] = TenPowerArr[i-1] * 10;
        }
        for(int i = 0; i < snumber.size(); i++){
            int j = snumber.size() - i - 1;
            result += statis[j]*(snumber[i]-'0'); 
            if(snumber[i] == '1'){
                int subint = 0;
                if(i != snumber.size()-1) subint = stoi(snumber.substr(i+1));
                result += subint + 1;
                if(subint == 0) return result;
            }
            else if(snumber[i] > '1') result += TenPowerArr[j];
        }
        return result;
    }
};