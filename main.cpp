// 【模板】
//#include <iostream>
//#include "utils.h"
//# include "my_solution/12/solution.cpp"   // 这里如果想跑哪一个题目的话，只要把中间的那个题号改掉就可以了
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
# include "my_solution/JZOffer04/solution.cpp"   // 这里如果想跑哪一个题目的话，只要把中间的那个题号改掉就可以了

int main() {

    Solution solution;  // 实例化题解文件中的类

    int target;
    vector<vector<int>> input = utils::getVector2D();
    cin >> target;
    if(solution.findNumberIn2DArray(input, target)) cout << "true\n";
    else cout << "false\n";

    return 0;
}