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
# include "my_solution/21/solution.cpp"   // 这里如果想跑哪一个题目的话，只要把中间的那个题号改掉就可以了

int main() {
    char c;
    Solution solution;  // 实例化题解文件中的类

    ListNode *h1 = (ListNode *)malloc(sizeof(ListNode));
    h1->val = 1;
    h1->next = nullptr;
    ListNode *h2 = (ListNode *)malloc(sizeof(ListNode));
    h2->val = 1;
    h2->next = nullptr;
    utils::createListNode(4, h1);
    utils::printListNode(h1);
    cout << "\n";
    utils::createListNode(8, h2);
    utils::printListNode(h2);
    cout << "\n";
    h1 = solution.mergeTwoLists(nullptr, h2);
    utils::printListNode(h1);
    return 0;
}