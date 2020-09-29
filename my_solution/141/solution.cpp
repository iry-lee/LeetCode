/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 两个指针，但是速度不同，差速指针
// 这个在剑指offer上做过，好不容易想起来了
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode * fastp = head, *slowp = head;
        bool flag = false;
        while(fastp != nullptr && slowp != nullptr){
            if(flag && (fastp == slowp || fastp->next == slowp)) return true;
            else{
                if(!flag) flag = true;
                slowp = slowp->next;
                fastp = fastp->next;
                if(fastp == nullptr) return false;
                else fastp = fastp->next;
            }
        }
        return false;
    }
};