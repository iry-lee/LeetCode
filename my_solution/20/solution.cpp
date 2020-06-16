//
// Created by 11029 on 2020/6/12.
//
// 本题是“栈”非常经典的应用

#include <stack>

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i = 0; i < s.size(); i++){
            if(st.empty()) {
                st.push(s[i]);
                continue;
            }
            if((s[i] == ')' && st.top() == '(')
               ||(s[i] == ']' && st.top() == '[')
               ||(s[i] == '}' && st.top() == '{'))
                st.pop();
            else st.push(s[i]);
        }
        return st.empty();
    }
};

// main.cpp
//#include <iostream>
//#include "utils.h"
//# include "my_solution/20/solution.cpp"   // 这里如果想跑哪一个题目的话，只要把中间的那个题号改掉就可以了
//
//int main() {
//    char c;
//    Solution solution;  // 实例化题解文件中的类
//
//    string input = utils::getString();
//    bool output = solution.isValid(input);
//    if(output) cout << "true";
//    else cout << "false";
//
//    return 0;
//}