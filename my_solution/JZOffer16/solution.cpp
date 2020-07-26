#include <iostream>

class Solution {
public:
    double myPow(double x, int n) {
        // 先处理一下特殊情况
        if(x == 1.0 || x == 0.0) return x;
        if(x == -1.0 && n % 2 == 0 || n == 0) return 1.0;
        if(x == -1.0 && n % 2 == 1) return x;

        // 可能需要二进制表示n，然后再开始计算
        double result = 1.0, table[33] = {0.0};
        int bit[33] = {0}, bitmax  = 0;
        bool positive = true;
        if(n == INT_MIN){
            positive = false;
            bitmax = 32;
            bit[bitmax] = 1;
        }
        else{
            if(n < 0){
                positive = false;
                n = n * -1;
            }
            unsigned int temp = n;
            int pow2 = 1;
            while(temp > 1){
                temp = temp >> 1;
                pow2 = pow2 << 1;
                bitmax++;
            }
            printf("pow2: %d\n", pow2);
            temp = n;
            printf("temp: %d\n", temp);
            for(int i = bitmax; i >= 0; i--){
                if(pow2 <= temp && temp > 0){
                    temp-=pow2;
                    bit[i] = 1;
                }
                pow2 = pow2 >> 1;
            }
        }

        // 建立一下double table[]
        // table[i] = table[i-1]^2;
        table[0] = x;
        for(int i = 1; i <= bitmax; i++){
            table[i] = table[i-1] * table[i-1];
            printf("%lf ", table[i-1]);
        }
        printf("\n");

        // 按照bit中和table中的对应关系
        for(int i = 0; i <= bitmax; i++){
            if(bit[i] == 1)
                result *= table[i];
        }
        if(positive) return result;
        else return 1.0/result;
    }
};