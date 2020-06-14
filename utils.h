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

class utils {
public:
    // 从控制台输入的'[a,b,c,d]'这样的格式中读入一个数组到程序中
    vector<int> static getVector();
    // 将程序中的vector打印成'[a,b,c,d]'这样的格式输出到控制台中
    void static printVector(const vector<int>& v);
    // 读入一个整数
    int static getInt();
    // 读入一个字符串 "string"，按照LeetCode的格式，引号 " 也算是输入的一部分，要去掉
    string static getString();
};

#endif //LEETCODE_UTILS_H
