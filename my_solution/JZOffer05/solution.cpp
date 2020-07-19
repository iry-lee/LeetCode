class Solution {
public:
    string replaceSpace(string s) {
        int ct = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ' ') ct++;
        }
        int len = s.size()+2*ct + 1;
        char _s [len];
        int s_ptr = s.size()-1;
        _s[len - 1] = '\0';
        for(int i = len - 2; i >= 0;){
            if(s[s_ptr] != ' '){
                _s[i] = s[s_ptr];
                i--; s_ptr--;
            }
            else{
                _s[i] = '0';
                _s[i-1] = '2';
                _s[i-2] = '%';
                i-=3; s_ptr--;
            }
        }
        return string(_s);
    }
};

// main.cpp

//#include <iostream>
//#include <cstdio>
//#include "utils.h"
//# include "my_solution/JZOffer05/solution.cpp"   // 这里如果想跑哪一个题目的话，只要把中间的那个题号改掉就可以了
//
//int main() {
//
//    Solution solution;  // 实例化题解文件中的类
//
//    cout << solution.replaceSpace(utils::getString());
//
//    return 0;
//}