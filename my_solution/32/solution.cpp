#include <string>
#include <stack>
#include <iostream>
using namespace std;

// 这是一个O(n)的方法，用到了栈
// 但我的运行速度在提交者里面还是垫底
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<char> brackets;
        stack<int> length;
        length.push(0);
        int maxLen = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                brackets.push('(');
                length.push(0);
            }
            else{ // s[i] == ')'
                if(brackets.empty()){
                    length.push(0);
                    continue;
                }
                else{
                    brackets.pop();
                    int num = length.top() + 2;
                    length.pop();
                    num += length.top();
                    if(num > maxLen) maxLen = num;
                    length.pop();
                    length.push(num);
                }
            }
        }
        return maxLen;
    }
};

// 这个方法的时间复杂度是O(n^2)
// 可以设置一个头指针一个尾指针，头指针固定，尾指针扩展
// 如何判断匹配失败？
// 1. 字符串匹配完了，栈里还剩下一堆
// 2. 栈里只有一个“)”
//class Solution {
//public:
//    int longestValidParentheses(string s) {
//        int headPtr = 0, tailPtr = 0, maxLen = 0;
//        stack<char> stk;
//        while(headPtr < s.size()) {
//            cout << "headPtr:\t" << headPtr << "\n";
//            cout << "tailPtr:\t" << tailPtr << "\n";
//            // 每次括号栈为空的时候就可以检查是否是最长的了
//            if(stk.empty()){
//                if(maxLen < tailPtr - headPtr)
//                    maxLen = tailPtr - headPtr;
//            }
//            if(tailPtr == s.size()){
//                while(!stk.empty()) stk.pop();
//                // 这里还是用++有点慢了
//                headPtr++;
//                while(s[headPtr] == ')') headPtr++;
//                tailPtr = headPtr;
//            }
//            if(stk.size() == 1 && stk.top() == ')'){
//                if(maxLen < tailPtr - headPtr) maxLen = tailPtr - headPtr - 1;
//                headPtr = tailPtr;
//                stk.pop();
//            }
//            char c = s[tailPtr++];
//            if(c == ')' && !stk.empty() && stk.top() == '('){
//                stk.pop();
//            }
//            else stk.push(c);
//        }
//        return maxLen;
//    }
//};

// main.cpp

//#include <iostream>
//#include <cstdio>
//#include "utils.h"
//# include "my_solution/32/solution.cpp"   // 这里如果想跑哪一个题目的话，只要把中间的那个题号改掉就可以了
//
//int main() {
//
//    Solution solution;  // 实例化题解文件中的类
//
//    string s = utils::getString();
//
//    cout << solution.longestValidParentheses(s);
//
//    return 0;
//}