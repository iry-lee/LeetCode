class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *a = new ListNode(0);
        ListNode *b = new ListNode(0);
        ListNode *aptr = a, *bptr = b;
        ListNode *ptr = head;
        while(ptr != nullptr){
            ListNode *temp = ptr->next;
            ptr->next = nullptr;
            if(ptr->val < x){
                aptr->next = ptr;
                aptr = aptr->next;
            }
            else{
                bptr->next = ptr;
                bptr = bptr->next;
            }
            
            ptr = temp;
        }

        aptr->next = b->next;
        return a->next;
    }   
};

// 可以分成三部分来存放链表中的节点
// 第一部分，按顺序存放比x小的节点
// 第二部分，存放大于或等于x的节点