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
// 这里是不是可以使用指针数组，意思是需要消耗额外的O(k)的空间复杂度

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode forehead(0);
        forehead.next = head;
        // 如果链表为空或者只有一个节点
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        // 否则就有大于等于2个节点

    }
};

// main.cpp
//#include <iostream>
//#include "utils.h"
//# include "my_solution/25/solution.cpp"   // 这里如果想跑哪一个题目的话，只要把中间的那个题号改掉就可以了
//
//int main() {
//    char c;
//    Solution solution;  // 实例化题解文件中的类
//
//    ListNode head(1);
//    ListNode *_head = solution.reverseKGroup(utils::createListNode(10, &head), 5);
//    utils::printListNode(_head);
//
//    return 0;
//}