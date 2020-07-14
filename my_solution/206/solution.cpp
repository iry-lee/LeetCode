//
// Created by 11029 on 2020/6/12.
//
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode *ptr1 = nullptr, *ptr2 = head;
        while(ptr2 != nullptr){
            ListNode *temp = ptr2->next;
            ptr2->next = ptr1;
            ptr1 = ptr2;
            ptr2 = temp;
        }
        return ptr1;
    }
};

// main.cpp
//#include <iostream>
//#include "utils.h"
//# include "my_solution/28/solution.cpp"   // 这里如果想跑哪一个题目的话，只要把中间的那个题号改掉就可以了
//
//int main() {
//    char c;
//    Solution solution;  // 实例化题解文件中的类
//
//    ListNode head(1);
//    utils::createListNode(10, &head);
//    utils::printListNode(&head);
//    cout << "\n";
//    utils::printListNode(solution.reverseList(&head));
//
//    return 0;
//}