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
#include "utils.h"
# include "my_solution/18/solution.cpp"   // 这里如果想跑哪一个题目的话，只要把中间的那个题号改掉就可以了

int main() {
    char c;
    Solution solution;  // 实例化题解文件中的类

    vector<int> input = utils::getVector();
    int target = utils::getInt();
    vector<vector<int>> output = solution.fourSum(input, target);
    utils::printVector2D(output);

    return 0;
}