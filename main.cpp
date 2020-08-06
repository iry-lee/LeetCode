//#include <iostream>
//#include <vector>
//#include <stack>
//#include <queue>
//#include <string>
//#include "utils.h"
//#include "my_solution/JZOffer19/solution.cpp"   // 这里如果想跑哪一个题目的话，只要把中间的那个题号改掉就可以了
//using namespace std;
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
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include "utils.h"
#include "my_solution/JZOffer33/solution.cpp"   // 这里如果想跑哪一个题目的话，只要把中间的那个题号改掉就可以了
using namespace std;

int main() {
    char c;
    Solution solution;  // 实例化题解文件中的类

    vector<int> input = utils::getVector();
    if(solution.verifyPostorder(input)) cout << "true\n";
    else cout << "false\n";

    return 0;
}