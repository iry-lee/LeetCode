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
# include "my_solution/25/solution.cpp"   // 这里如果想跑哪一个题目的话，只要把中间的那个题号改掉就可以了

int main() {
    char c;
    Solution solution;  // 实例化题解文件中的类

    ListNode head(1);
    ListNode *_head = solution.reverseKGroup(utils::createListNode(12, &head), 4);
    utils::printListNode(_head);

    return 0;
}