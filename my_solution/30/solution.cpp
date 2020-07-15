class Solution {
public:
    struct hash_string{
        int hash;
        string s;
    };
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        int total_len = 0;      // 目标串的总长度
        int a = 26;             // base value for rolling hash
        int modulus = 1 << 31;  // modulus for rolling hash
        for(int i = 0; i < words.size(); i++){
            total_len += words[i].size();
        }
        vector <hash_string> choices;   // words的全排列数量的选项
        for
        // 哈希值匹配上以后，最好还是逐字符比较一下比较保险，防止哈希值碰撞

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