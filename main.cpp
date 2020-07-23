// 【模板】
//#include <iostream>
//#include "utils.h"
//#include "my_solution/12/solution.cpp"   // 这里如果想跑哪一个题目的话，只要把中间的那个题号改掉就可以了
//
//int main() {
//    char c;
//    Solution solution;  // 实例化题解文件中的类
//
//    --------------- insert your code here --------------
//
//    return 0;
//}

#include <iostream>
#include <cstdio>
#include "utils.h"
#include "my_solution/JZOffer12/solution.cpp"   // 这里如果想跑哪一个题目的话，只要把中间的那个题号改掉就可以了

int main() {

    Solution solution;  // 实例化题解文件中的类

    vector<char> c1 = {'A','B','C','E'};
    vector<char> c2 = {'S','F','E','S'};
    vector<char> c3 = {'A','D','E','E'};
    vector<vector<char>> vvc = {c1, c2, c3};

    cout << solution.exist(vvc, "ABCESEEEFS");

    return 0;
}