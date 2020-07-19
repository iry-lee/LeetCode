/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <stack>

class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        vector<int> result;
        stack<int> s;
        ListNode *temp = head;
        while(temp != nullptr){
            s.push(temp->val);
            temp = temp->next;
        }
        while (!s.empty()){
            result.push_back(s.top());
            s.pop();
        }
        return result;
    }
};