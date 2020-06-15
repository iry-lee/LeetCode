//
// Created by 11029 on 2020/6/12.
//

#ifndef LEETCODE_UTILS_H
#define LEETCODE_UTILS_H

#include <vector>
#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

// 定义一个单向链表的结构体
struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};


class utils {
public:
    // 下面涉及到字符串的函数，对于空格也是格式严格的，鲁棒性较差。

    // 从控制台输入的'[a,b,c,d]'这样的格式中读入一个数组到程序中
    vector<int> static getVector();

    // 读入一个整数
    int static getInt();

    // 读入一个字符串 "string"，按照LeetCode的格式，引号 " 也算是输入的一部分，要去掉
    string static getString();

    // 读入一个字符串数组，当前的问题是，如果输入一个 “[]”会出问题
    vector<string> static getVectorString();

    // 打印数组。将程序中的vector打印成'[a,b,c,d]'这样的格式输出到控制台中
    void static printVector(const vector<int>& v);

    // 打印二维向量
    // 将程序中的二维vector打印成:
    // [
    //      [-1, 0, 1],
    //      [-1, -1, 2]
    // ]
    void static printVector2D(const vector<vector<int>> &v);

    // 打印字符串，字符串的内容在双引号之间，例如："adsadas"
    void static printString(const string& s);

    // 打印字符串数组，格式例如：["aa", "ac"].
    void static printVectorString(const vector<string> &s);

    // 打印链表
    void static printListNode(ListNode *head);

    // 自动创建一个链表，参数n为链表的长度，返回链表的头节点
    ListNode static *createListNode(int n, ListNode *head);
};

#endif //LEETCODE_UTILS_H
