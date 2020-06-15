//
// Created by 11029 on 2020/6/12.
//

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include "../../utils.h"

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *forehead = (ListNode*)malloc(sizeof(ListNode));
        forehead->next = head;
        forehead->val = INT_MIN; // 这里无所谓，我随便赋一个值
        //如果只有一个节点，直接返回null
        if(head->next == nullptr)
            return nullptr;
        ListNode *pt, *_pt;
        int ct = n;
        pt = forehead, _pt = forehead;
        while(pt -> next != nullptr){
            if(ct == 0){
                _pt = _pt->next;
            }
            else{
                ct --;
            }
            pt = pt->next;
        }
        ListNode *pt1 = _pt->next, *pt2 = pt1->next;
        _pt->next = pt2;
        return forehead->next;
    }
};

// 本题思路对，但是用时刚好是较好的答案的两倍，明明就遍历了一遍，感觉就像是我遍历了两遍
/*
本地测试时，main.cpp的内容：

#include <iostream>
#include "utils.h"
# include "my_solution/19/solution.cpp"   // 这里如果想跑哪一个题目的话，只要把中间的那个题号改掉就可以了

int main() {
    char c;
    Solution solution;  // 实例化题解文件中的类

    int n, m;
    cin >> n >> m;
    if(n < m) {
        cout << "'n' must large or equal to 'm'";
        return 0;
    }
    ListNode *head = (ListNode *)malloc(sizeof(ListNode));
    head->val = 1;
    head->next = nullptr;
    head = utils::createListNode(n, head);
    utils::printListNode(head);
    cout << "\n";
    head = solution.removeNthFromEnd(head, m);
    utils::printListNode(head);

    return 0;
}
 */