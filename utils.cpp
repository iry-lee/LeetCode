//
// Created by 11029 on 2020/6/12.
//

#include "utils.h"


vector<int> utils::getVector(){
    // 针对是这样的输入：[1,8,6,2,5,4,8,3,7]
    vector<int> result;
    getchar(); // 先把'['吃进来
    char c = (char)getchar();
    while(c != '\n') {
        int number = 0;
        int flag = 1;
        while (c != ',' && c != ']') {
            // 读入正负号
            if(c == '-'){
                flag = -1;
                c = getchar();
            }
            else if(c == '+'){
                c = getchar();
            }
            number = number * 10 + c - '0';
            c = (char) getchar();
        }
        c = (char)getchar();
        result.push_back(number*flag);
    }
    return result;
}

int utils::getInt() {
    int n;
    cin >> n;
    return n;
}

string utils::getString() {
    string input;
    char c = (char)getchar(); // 把第一个 " 吃掉
    c = (char)getchar();
    while(c != '"'){
        string part (1, c);
        input.append(part);
        c = (char)getchar();
    }
    c = getchar(); //把最后的回车吃掉
    return input;
}

vector<string> utils::getVectorString() {
    vector<string> input;
    char c = (char)getchar();  // 把'['吃掉
    while(c != ']'){
        input.push_back(getString());
        c = getchar();
    }
    return input;
}

void utils::printVector(const vector<int>& v){
    printf("[");
    for(int i = 0; i < v.size(); i++){
        printf("%d", v[i]);
        if(i != v.size()-1)
            printf(",");
    }
    printf("]\n");
}

void utils::printVector2D(const vector<vector<int>> &v) {
    printf("[\n");
    for(int i = 0; i < v.size(); i++){
        printf("   [");
        for(int j = 0; j < v[i].size(); j++){
            printf("%d", v[i][j]);
            if(j != v[i].size()-1){
                printf(",");
            }
        }
        printf("]");
        if(i != v.size()-1)
            printf(",");
        printf("\n");
    }
    printf("]");
}

void utils::printString(const string& s) {
    cout << "\"";
    cout << s;
    cout << "\"";
}

void utils::printVectorString(const vector<string> & s){
    printf("[");
    for(int i = 0; i < s.size(); i++){
        printString(s[i]);
        if(i != s.size() - 1)
            printf(",");
    }
    printf("].");
}

void utils::printListNode(ListNode *head){
    ListNode *pt = head;
    while(pt != nullptr){
        printf("(%d)", pt->val);
        if(pt->next != nullptr){
            cout << "->";
        }
        pt = pt->next;
    }
}

ListNode* utils::createListNode(int n, ListNode *head){
    if(n <= 0) return nullptr;
    ListNode *pt = head;
    for(int i = 1; i < n; i++){
        ListNode *temp = (ListNode*)malloc(sizeof(ListNode));
        temp->val = i + 1;
        temp->next = nullptr;
        pt->next = temp;
        pt = temp;
    }
    return head;
}

