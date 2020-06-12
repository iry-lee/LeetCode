//
// Created by 11029 on 2020/6/12.
//

#ifndef LEETCODE_UTILS_H
#define LEETCODE_UTILS_H

#include <vector>
#include <stdio.h>

using namespace std;

class utils {
public:
    // 从控制台输入的'[a,b,c,d]'这样的格式中读入一个数组到程序中
    vector<int> static getVector();
    // 将程序中的vector打印成'[a,b,c,d]'这样的格式输出到控制台中
    void static printVector(const vector<int>& v);
};

#endif //LEETCODE_UTILS_H
