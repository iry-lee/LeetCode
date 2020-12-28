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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *prehead = new ListNode(0);
        ListNode *parthead = new ListNode(0);
        int ct = 1;
        ListNode *ptr = head, *preptr = prehead, *partptr = parthead;
        while(ptr != nullptr){
            ListNode *temp = ptr->next;
            ptr->next = nullptr;
            if(ct == n){
                preptr->next = ptr;
                preptr = ptr;
                if(parthead->next != nullptr) {
                    preptr->next = parthead->next;
                    preptr = partptr;
                }
            }
            else if(ct == m){
                partptr->next = ptr;
                partptr = ptr;
            }
            else if(ct > m && ct < n){
                ListNode * partnext = parthead->next;
                parthead->next = ptr;
                ptr->next = partnext;
            }
            else{
                preptr->next = ptr;
                preptr = ptr;
            }
            ptr = temp;
            ct++;
        }
        return prehead->next;
    }
};