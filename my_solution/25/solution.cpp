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
        // 声明大小为k的数组存放指针，数组最后一个
        ListNode forehead(0);
        ListNode *begin = &forehead;
        forehead.next = head;
        vector<ListNode*> parray(k+1, nullptr);
        // 如果链表为空或者只有一个节点
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        // 否则就有大于等于2个节点
        // 操作以k为周期
        while(1){
            // 给k个指针赋值
            int i;
            for(i = k; i >= 0 && begin != nullptr; i--){
                parray[i] = begin;
                begin = begin->next;
            }
            if(i > -1) break;
            // ########  开始大交换  #########
            // 把连接下一个周期的节点得先存起来
            ListNode *temp = parray[0]->next;
            for(int j = k - 1; j > 0; j--){
                parray[j-1]->next = parray[j];
            }
            parray[k]->next = parray[0];
            parray[k-1]->next = temp;
            begin = parray[k-1];
        }
        return forehead.next;
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