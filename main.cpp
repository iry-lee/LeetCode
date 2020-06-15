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
# include "my_solution/19/solution.cpp"   // 这里如果想跑哪一个题目的话，只要把中间的那个题号改掉就可以了

int main() {
    char c;
    Solution solution;  // 实例化题解文件中的类

    int n, m;
    cin >> n >> m;
    if(n < m) {
        cout << "'n' must large or equal to 'm'";
        return 0;
    }
    ListNode *head = (ListNode *)malloc(sizeof(ListNode));
    head->val = 1;
    head->next = nullptr;
    head = utils::createListNode(n, head);
    utils::printListNode(head);
    cout << "\n";
    head = solution.removeNthFromEnd(head, m);
    utils::printListNode(head);

    return 0;
}