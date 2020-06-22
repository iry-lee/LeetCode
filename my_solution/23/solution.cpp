/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


// 这种方法直接借助了之前21题合并两个有序链表中写的函数

#include "../../utils.h"

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return nullptr;
        else if(lists.size() == 1) return lists[0];
        else{
            int len = (int)lists.size();
            for(int i = 0; i < len/2; i++){
                if(len % 2 == 0){
                    lists[i] = mergeTwoLists(lists[i], lists[len/2 + i]);
                }
                else{
                    lists[i] = mergeTwoLists(lists[i], lists[len/2 + i + 1]);
                }
            }
            for(int i = 0; i < len/2; i++) lists.pop_back();
            return mergeKLists(lists);
        }
    }
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