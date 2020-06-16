//
// Created by 11029 on 2020/6/12.
//

#include "../../utils.h"

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head, *pt1 = l1, *pt2 = l2;

        //确定一个 head
        if(pt1 == nullptr && pt2 == nullptr) return nullptr;
        else if(pt1 == nullptr) {head = pt2; pt2 = pt2 -> next;}
        else if(pt2 == nullptr) {head = pt1; pt1 = pt1 -> next;}
        else if(pt1->val < pt2->val){head = pt1; pt1 = pt1->next;}
        else{head = pt2; pt2 = pt2->next;}

        //然后开始 merge
        ListNode *pt = head;
        while (1){
            if(pt1 == nullptr){
                pt->next = pt2;
                break;
            }
            else if(pt2 == nullptr){
                pt->next = pt1;
                break;
            }
            else if(pt1->val < pt2->val){
                pt->next = pt1;
                pt = pt1;
                pt1 = pt1->next;
            }
            else{
                pt->next = pt2;
                pt = pt2;
                pt2 = pt2->next;
            }
        }
        return head;
    }
};

// main.cpp
//#include <iostream>
//#include "utils.h"
//# include "my_solution/21/solution.cpp"   // 这里如果想跑哪一个题目的话，只要把中间的那个题号改掉就可以了
//
//int main() {
//    char c;
//    Solution solution;  // 实例化题解文件中的类
//
//    ListNode *h1 = (ListNode *)malloc(sizeof(ListNode));
//    h1->val = 1;
//    h1->next = nullptr;
//    ListNode *h2 = (ListNode *)malloc(sizeof(ListNode));
//    h2->val = 1;
//    h2->next = nullptr;
//    utils::createListNode(4, h1);
//    utils::printListNode(h1);
//    cout << "\n";
//    utils::createListNode(8, h2);
//    utils::printListNode(h2);
//    cout << "\n";
//    h1 = solution.mergeTwoLists(nullptr, h2);
//    utils::printListNode(h1);
//    return 0;
//}