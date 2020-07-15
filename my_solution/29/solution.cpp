/*
给定两个整数，被除数 dividend 和除数 divisor。将两数相除，要求不使用乘法、除法和 mod 运算符。
返回被除数 dividend 除以除数 divisor 得到的商。
整数除法的结果应当截去（truncate）其小数部分，例如：truncate(8.345) = 8 以及 truncate(-2.7335) = -2
 */

// 转成字符串，然后模拟除法？
// 要么转二进制，然后模拟除法？
// 这两种方法都用到了除法呀
// 看了一下很多解答里介绍了移位操作
// 还有一个要注意的点是，当 dividend 是INT_MIN，divisor是-1的时候，会溢出

class Solution {
public:
    int divide(int dividend, int divisor) {
        bool d1neg = false, d2neg = false;
        long result = 0, d1long = (long)dividend, d2long = (long)divisor; // 当 dividend 是INT_MIN，divisor是-1的时候，会溢出
        if(d1long < 0) {d1neg = true; d1long *= -1; cout << "sadasd\n";}
        if(d2long < 0) {d2neg = true; d2long *= -1;}
        long _dividend = d1long, _divisor = d2long;
        // cout << "_dividend:\t" << _dividend << "\n";
        // cout << "_divisor:\t" << _divisor << "\n";
        while (_divisor <= _dividend) {
            int temp = 1;
            while (_divisor << 2 < _dividend) {
                _divisor = _divisor << 2;
                temp = temp << 2;
            }
            result += temp;
            _dividend -= _divisor;
            // cout << "_dividend:\t" << _dividend << "\n";
            // cout << "_divisor:\t" << _divisor << "\n";
            _divisor = d2long;
        }
        if(d1neg != d2neg) result *= -1;
        if(result > INT_MAX) result = INT_MAX;
        return result;
    }
};

// main.cpp
//#include <iostream>
//#include <cstdio>
//#include "utils.h"
//# include "my_solution/29/solution.cpp"   // 这里如果想跑哪一个题目的话，只要把中间的那个题号改掉就可以了
//
//int main() {
//
//    Solution solution;  // 实例化题解文件中的类
//
//    int m, n;
//    cin >> m >> n;
//    cout << solution.divide(m, n);
//
//    return 0;
//}