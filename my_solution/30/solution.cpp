#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>
#include <memory.h>
using namespace std;

class Solution {
public:
    struct domain{
        int begin;
        int end;
        int *table;
        int table_size;
    };
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        // 先找到第一个word的出现的所有的位置，得到一组区间
        // 对于每一个区间，判断区间前后是否有相邻的words，有则扩展区间范围，直到所有的单词都包含在该区间中
        // 没有则验证下一个区间
        // 直到所有的可能的区间都被查找完毕
        vector<domain> choices;
        if(words.empty()) return result;    // 如果words为空的话，返回空
        // 对于words[0]，先初始化 choices
        int position = 0;
        while (1){
            position = s.find(words[0], position);
            if(position == string::npos) break;
            else{
                // 加入新的choice
                cout << "[" << position << "," << position+words[0].size() << "]\n";
                int table[words.size()];
                memset(table, 0, sizeof(int)*words.size());
                table[0] = 1;
                choices.push_back({position, position + (int)words[0].size(), table, (int)words.size()});
                position++;
            }
        }
        // 如果choice为空，说明words[0]就不存在
        if (choices.empty()) return result;
        if (words.size() == 1){
            for(int i = 0; i < choices.size(); i++){
                result.push_back(choices[i].begin);
            }
            return result;
        }
        // 开始区间扩展
        for (int i = 0; i < choices.size(); i++){
            for (int j = 1; j < words.size(); j++){
                // 对于没有添加入区间的才尝试添加
                if(choices[i].table[j] == 0){

                }
            }
        }
        return result;
    }
};

// main.cpp

//#include <iostream>
//#include <cstdio>
//#include "utils.h"
//# include "my_solution/30/solution.cpp"   // 这里如果想跑哪一个题目的话，只要把中间的那个题号改掉就可以了
//
//int main() {
//
//    Solution solution;  // 实例化题解文件中的类
//
//    string s = utils::getString();
//    vector<string> words = utils::getVectorString();
//
//    utils::printVector(solution.findSubstring(s, words));
//
//    return 0;
//}