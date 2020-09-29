/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// 时间复杂度O(nlogn)，那么想到就是quick sort 和 merge sort
// 但是链表中做快排需要下标与取值是对应的，那就只有merge sort了
// 先用两个指针，一个的速度是另一个的两倍，然后就可以找到链表的中点，一分为二
class Solution {
public:
    ListNode* mergeList(ListNode *a, ListNode *b){
        ListNode *head = (ListNode*)malloc(sizeof(ListNode));
        ListNode *ptr = head;
        while(a != nullptr && b != nullptr){
            if(a->val < b->val){
                head->next = a;
                a = a->next;
                head = head -> next;
            }
            else{
                head->next = b;
                b = b->next;
                head = head->next;
            }
        }
        while(a != nullptr){
            head->next = a;
            a = a->next;
            head = head->next;
        }
        while(b != nullptr){
            head->next = b;
            b = b->next;
            head = head->next;
        }
        head->next = nullptr;
        return ptr->next;
    }
    ListNode* sortList(ListNode* head) {
        ListNode* fast = head, *slow = head; 
        int ct = 0;  // 计算链表的总长度
        while(fast != nullptr && fast->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;
            ct += 2;
        }
        if(fast != nullptr) ct++;
        // 根据当前链表的长度需要判断一下做啥操作
        // 比如总长度为0？为1？为2？，总长度用ct来知道
        if(ct == 0) return nullptr;
        else if(ct == 1) return head;
        else if(ct == 2){
            ListNode *next = head->next;
            if(head->val > next->val){
                ListNode *temp = next->next;
                head->next = temp;
                next->next = head;
                return next;
            }
            return head;
        }
        else{
            //先划分
            ListNode *temp = slow->next;
            slow->next = nullptr;
            ListNode * a = sortList(head);
            ListNode * b = sortList(temp);
            // 合并a b
            return mergeList(a, b);
        }
    }  
};