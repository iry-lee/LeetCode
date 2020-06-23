//
// Created by 11029 on 2020/6/12.
//
/*
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    int INTERVAL = 2;
    ListNode* swapPairs(ListNode* head) {
        struct ListNode result(0);
        result.next = head;
        // 如果是一个空链表或者链表只有一个节点
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        // 如果节点个数大于等于2
        ListNode * ptr1 = head->next;
        ListNode * ptr2 = &result;
        while(1){
            // 先交换
            ListNode * temp = ptr2->next;
            ptr2->next = ptr1;
            temp->next = ptr1->next;
            ptr1->next = temp;
            // 往后推
            ptr1 = temp;
            int i = 0;
            while (i < INTERVAL && ptr1 != nullptr){
                ptr1 = ptr1->next;
                ptr2 = ptr2->next;
                i++;
            }
            if(ptr1 == nullptr) break;
        }
        return result.next;
    }
};

// main.cpp
//#include <iostream>
//#include "utils.h"
//# include "my_solution/24/solution.cpp"   // 这里如果想跑哪一个题目的话，只要把中间的那个题号改掉就可以了
//
//int main() {
//    char c;
//    Solution solution;  // 实例化题解文件中的类
//
//    ListNode head(1);
//    ListNode *_head = solution.swapPairs(utils::createListNode(3, &head));
//    utils::printListNode(_head);
//
//    return 0;
//}