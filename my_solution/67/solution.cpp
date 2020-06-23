//
// Created by 11029 on 2020/6/12.
//

class Solution {
public:
    string addBinary(string a, string b) {
        if(a.size() == 0 && b.size() == 0) return "0";
        if(a.size() == 0) return b;
        if(b.size() == 0) return a;

        string c (max(a.size(), b.size()) + 1, '0');
        int i = (int)a.size() - 1, j = (int)b.size() - 1, k = (int)c.size() - 1;
        int up = 0;
        for(; i >= 0 && j >= 0; i--, j--){
            int num = a[i] - '0' + b[j] - '0' + up;
            if(num == 0) {up = 0; c[k--] = '0';}
            else if(num == 1) {up = 0; c[k--] = '1';}
            else if(num == 2) {up = 1; c[k--] = '0';}
            else if(num == 3) {up = 1; c[k--] = '1';}
        }
        for(; i>=0; i--){
            int num = a[i] - '0' + up;
            if(num == 0) {up = 0; c[k--] = '0';}
            else if(num == 1) {up = 0; c[k--] = '1';}
            else if(num == 2) {up = 1; c[k--] = '0';}
            else if(num == 3) {up = 1; c[k--] = '1';}
        }
        for(; j >= 0; j--){
            int num = b[j] - '0' + up;
            if(num == 0) {up = 0; c[k--] = '0';}
            else if(num == 1) {up = 0; c[k--] = '1';}
            else if(num == 2) {up = 1; c[k--] = '0';}
            else if(num == 3) {up = 1; c[k--] = '1';}
        }

        // 把最后的进位处理掉
        if(up == 1) c[k] = '1';

        if(c[0] == '0' && c.size() > 1)
            return c.substr(1);
        return c;
    }
};

//main.cpp
//#include <iostream>
//#include "utils.h"
//# include "my_solution/67/solution.cpp"   // 这里如果想跑哪一个题目的话，只要把中间的那个题号改掉就可以了
//
//int main() {
//    char c;
//    Solution solution;  // 实例化题解文件中的类
//
//    cout << solution.addBinary(utils::getString(), utils::getString());
//
//    return 0;
//}