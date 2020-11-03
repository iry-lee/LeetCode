// 这个题在剑指offer里面做过，在这里换一种做法
// 之前的做法是转二进制
// 这次想着对n不断除2
class Solution {
public:
    double myPow(double x, int n) {
        // 处理一下x的输入
        if(x == 0.0) return 0.0;
        else if(x == 1.0) return 1.0;
        // 处理一下n的输入
        if(n == 1) return x;
        else if(n == 0) return 1;
        else if(n == -1) return 1/x;
        // 记录一下n的正负
        int positive = true;
        // 处理一下n可能为INT_MIN的情况
        if(n == INT_MIN){
            x = x*x;
            positive = false;
            n = 0x40000000;
        }
        else if(n < 0) {
            n = -1*n;
            positive = false;
        }
        // 开始真正的计算
        stack<double> factor;
        double ans = 1.0;
        while(n > 0){
            if(n % 2 == 1) factor.push(x);
            n = n / 2;
            x = x*x;
        }
        while(!factor.empty()){
            ans *= factor.top();
            factor.pop();
        }
        if(positive) return ans;
        else return 1 / ans;
    }
};