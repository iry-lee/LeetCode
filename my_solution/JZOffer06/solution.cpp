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

// main.cpp

//#include <iostream>
//#include <cstdio>
//#include "utils.h"
//# include "my_solution/JZOffer06/solution.cpp"   // 这里如果想跑哪一个题目的话，只要把中间的那个题号改掉就可以了
//
//int main() {
//
//    Solution solution;  // 实例化题解文件中的类
//    auto *head = (ListNode*)malloc(sizeof(ListNode));
//    head->val = 1;
//    head = utils::createListNode(10, head);
//    utils::printListNode(head);
//    cout << "\n";
//    vector<int> result;
//    result = solution.reversePrint(head);
//    utils::printVector(result);
//
//    return 0;
//}