//
// Created by 11029 on 2020/6/12.
//
#include <map>

class Solution {
public:
    int romanToInt(string s) {
        map<char, int> m = {{'I', 1}, {'V', 5},
                              {'X', 10}, {'L', 50},
                              {'C', 100}, {'D', 500},
                              {'M', 1000}};
        int number = 0;
        for (int i = (int)s.size() - 1; i > -1; i--){
            int value = m.operator[](s[i]), _value = 0, flag = 1;
            if(i < (int)s.size() - 1)
                _value = m.operator[](s[i+1]);
            if(_value > value)
                flag = -1;
            number += flag*value;
        }
        return number;
    }
};