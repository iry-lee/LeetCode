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
# include "my_solution/26/solution.cpp"   // 这里如果想跑哪一个题目的话，只要把中间的那个题号改掉就可以了

int main() {
    char c;
    Solution solution;  // 实例化题解文件中的类

    // vector<int> input = {};   //测试空数组
    // vector<int> input = {1,1,1,1,2,2,3,4,4,4,4,5,6,6,6,7,8,9,10};  //测试普通输入
    // vector<int> input = {1,1,1,1,1,1};   //测试全重复
    // vector<int> input = {1,2,3,4,5,6,7,8};   //测试wuchongf
    vector<int> input = {0,1,1,1,1,1,1,1};
    cout << solution.removeDuplicates(input) << "\n";
    utils::printVector(input);

    return 0;
}