//
// Created by 11029 on 2020/6/12.
//

class Solution {
public:
    string multiply(string num1, string num2) {
        string snumber (num2.size() + num1.size(), '0');
        for(int i = (int)num2.size() - 1; i > -1; i--){
            int up = 0;
            int k = num1.size() + num2.size() - 1 - ((num2.size() - 1) - i);
            for(int j = (int)num1.size() - 1; j > -1; j--){
                int num = (snumber[k] - '0') + up + (num1[j] - '0') * (num2[i] - '0');
                snumber[k] = num % 10 + '0';
                up = num / 10;
                k--;
            }
            // 把最后的进位清掉
            while(up > 0) {
                int num = (snumber[k] - '0') + up;
                snumber[k] = num % 10 + '0';
                up = num / 10;
                k--;
            }
        }
        // 把前置的0清掉
        int k = 0;
        while (snumber[k] == '0'){
            k++;
        }
        if(k == num2.size() + num1.size()){
            return "0";
        }
        else{
            return snumber.substr(k, snumber.size()-k);
        }
    }
};

//
// 【另一种思路】
// abc*de 也可以看成是多项式乘法
// (a*100 + b*10 + c*1) * (d*10 + e*1)
// = a*d*1000 + (a*e + b*d)*100 + (c*d + b*e)*10 + c*e*1
//