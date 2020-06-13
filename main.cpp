#include <iostream>
#include "utils.h"
# include "my_solution/11/solution.cpp"   // 这里如果想跑哪一个题目的话，只要把中间的那个题号改掉就可以了
// #include "solution.cpp"

int main() {
    char c;
    vector<int> input = utils::getVector();
    Solution solution;

    printf("%d\n", solution.maxArea(input));

    return 0;
}

