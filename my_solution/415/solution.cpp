//
// Created by 11029 on 2020/6/15.
//
#include <string>
using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        string result;
        int len = max(num1.size(), num2.size())+1;
        string number (len, '0');
        int j = num1.size() - 1, k = num2.size() - 1;
        int up = 0;
        for(int i = len - 1; i > -1; i--){
            int n = up;
            if(j >= 0) n += num1[j--] - '0';
            if(k >= 0) n += num2[k--] - '0';
            number[i] = n % 10 + '0';
            up = n / 10;
        }
        j = 0;
        while(number[j] == '0'){
            j++;
        }
        result.append(number.substr(j, len - j));
        if(result.size() == 0)
            result.append("0");
        return result;
    }
};