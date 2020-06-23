//
// 【解题思路】
// 主要的难点在于，可能会有很多种匹配的方式，其中一种能够匹配上，其他的几种都匹配不上
// 这其实就需要考虑递归或者建栈。如何建立分支也是需要关注的问题
//
// 看了一下答案，介绍的方法是动态规划的方法
//

class Solution {
public:
    bool isMatch(string s, string p) {

    }
};

/*
【题干】：
给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。

'.' 匹配任意单个字符
'*' 匹配零个或多个前面的那一个元素
所谓匹配，是要涵盖 整个 字符串 s的，而不是部分字符串。

说明:
s 可能为空，且只包含从 a-z 的小写字母。
p 可能为空，且只包含从 a-z 的小写字母，以及字符 . 和 *。

*/
// 这个方法由于递归的次数较多，耗时太长
//class Solution {
//public:
//    bool isMatch(string s, string p) {
//        // 建立两个指针，分别对应s与p
//        int i = 0, j = 0, len = 0;
//        if(s.size() == 0){
//            for(int k = 0; k < p.size(); k++){
//                if(p[k] != '*') len++;
//                else len --;
//            }
//            if(len == 0) return true;
//        }
//        if(p == ".*") return true;
//        while(i < s.size() && j < p.size()){
//            //cout << "s:" << s.substr(i) << "\n";
//            //cout << "p:" << p.substr(j) << "\n";
//            // a-z
//            if(p[j] >= 'a' && p[j] <= 'z'){
//                // [a-z]*
//                if(j+1 < p.size() && p[j+1] == '*'){
//                    // 此情况其实与 .* 相似
//                    // [a-z]* 用多次
//                    string _s2 = s.substr(i+1);
//                    string _p2 = p.substr(j);
//                    // [a-z]* 一次也不用
//                    string _s3 = s.substr(i);
//                    string _p3 = p.substr(j+2);
//                    return (s[i] == p[j] && isMatch(_s2, _p2)) || isMatch(_s3, _p3);
//                }
//                    // [a-z]
//                else{
//                    if(s[i] == p[j]){ i++; j++;}
//                    else return false;
//                }
//            }
//                // .
//            else if(p[j] == '.'){
//                // [.]*
//                if(j+1 < p.size() && p[j+1] == '*'){
//                    // .* 用多次
//                    string _s2 = s.substr(i+1);
//                    string _p2 = p.substr(j);
//                    // .* 一次也不用
//                    string _s3 = s.substr(i);
//                    string _p3 = p.substr(j+2);
//                    return isMatch(_s2, _p2) || isMatch(_s3, _p3);
//                }
//                    // [.]
//                else{ i++; j++;}
//            }
//        }
//        while(j + 1 <= (int)p.size() - 1 && p[j+1] == '*'){
//            j+=2;
//        }
//        return (j > (int)p.size()-1 && i > (int)s.size()-1);
//    }
//};

// main.cpp
//#include <iostream>
//#include "utils.h"
//# include "my_solution/10/solution.cpp"   // 这里如果想跑哪一个题目的话，只要把中间的那个题号改掉就可以了
//
//int main() {
//    char c;
//    Solution solution;  // 实例化题解文件中的类
//
//    string s = utils::getString();
//    string p = utils::getString();
//
//    cout << solution.isMatch(s, p);
//
//    return 0;
//}