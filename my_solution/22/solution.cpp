//
// Created by 11029 on 2020/6/12.
//
//
// 【思路1】
// 这个题型是之前没有遇到过的，我当前的思路是找一下完整的"()"，
// 然后增加括号无非就是就是在"()"后面放一个或者里面嵌套一个，这两种情况可以表示成一个二叉树。
// 但如果就是这样的话，可能会产生重复的情况。全生成一遍然后再去重显然有点暴力。
// 为了防止重复，可能需要只对"..()()"同一层有多个括号，只在最后一个括号后面加并列的括号
//
// 【思路2】
// 想到了一个方法 “(((( ... ))))” 从左括号最里面的一直到第一个左括号，选择其中的做反转。
// 逐一反转。
//
// 【思路3】
// 思路2实在是有点麻烦难以实现，学习了一下官方给出的第三种方法
// 有这样的一个认识，当 n>=1 时，括号序列都是由 (a)b 组成的，因为括号序列的第一个一定是一个左括号
//
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> output;
        if (n == 0) return output;
        else if (n == 1){
            string s = "()";
            output.push_back(s);
        }
        else if(n == 2){
            string s1 = "(())", s2 = "()()";
            output.push_back(s1);
            output.push_back(s2);
        }
        else{
            for(int i = 0; i < n; i++){
                vector<string> v_a = generateParenthesis(i);
                vector<string> v_b = generateParenthesis(n-1-i);
                if(v_a.empty()){
                    for(int k = 0; k < v_b.size(); k++){
                        string temp = "()";
                        temp.append(v_b[k]);
                        output.push_back(temp);
                    }
                }
                else if (v_b.empty()){
                    for(int j = 0; j < v_a.size(); j++){
                        string temp = "(";
                        temp.append(v_a[j]);
                        temp.append(")");
                        output.push_back(temp);
                    }
                }
                else{
                    for(int j = 0; j < v_a.size(); j++){
                        for(int k = 0; k < v_b.size(); k++){
                            string temp = "(";
                            temp.append(v_a[j]);
                            temp.append(")");
                            temp.append(v_b[k]);
                            output.push_back(temp);
                        }
                    }
                }
            }
        }
        return output;
    }
};

// main.cpp
//#include <iostream>
//#include "utils.h"
//# include "my_solution/22/solution.cpp"   // 这里如果想跑哪一个题目的话，只要把中间的那个题号改掉就可以了
//
//int main() {
//    char c;
//    Solution solution;  // 实例化题解文件中的类
//
//    int n;
//    cin >> n;
//    vector<string> output = solution.generateParenthesis(n);
//    utils::printVectorString(output);
//
//    return 0;
//}

// ########### 好吧，这种方法不对，在n=1~3的时候没有问题，到了4的时候，这种方法生成不了 "(())(())" #########
// 在 n=4 的时候，我这个方法没有生成"(())(())"却生成了一个重复的，虽然总数是对的，但是其实不一样。
// 我错就错在，这个方法都是用 n-1 的情况再增加一个括号来得到 n 的情况，而 n = 4 的时候也可以是 2 + 2 这种情况
//class Solution {
//public:
//    vector<string> generateParenthesis(int n) {
//        vector<string> output;
//        if(n == 0) return output;
//        else output.emplace_back("()");
//
//        for(int i = 1; i < n; i++){
//            int len = output.size();
//            for(int j = 0; j < len; j++){
//                // 一般是有三种情况，只有全是"()"并列的时候只有（1，3）（或者（2，3））两种情况
//                // 那么可以不可以每次把这种情况放在固定的位置比如 output[0]，这样就剩下了遍历
//                // 1. (xxx)
//                string temp = "(";
//                output.push_back(temp.append(output[j]).append(")"));
//                // 2. () xxx
//                if(j != 0){
//                    temp = "()";
//                    output.push_back(temp.append(output[j]));
//                }
//                // 3. xxx ()
//                temp = "()";
//                output[j].append(temp);
//            }
//        }
//        return output;
//    }
//};