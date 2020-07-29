#include <string>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string result = "1";
        while(n > 1){
            string temp;
            int ct = 1, number_before = result[0] - '0';
            for(int i = 1; i < result.size(); i++){
                if(result[i] - '0' == number_before) {
                    ct++;
                }
                else{
                    temp.push_back('0' + ct);
                    temp.push_back('0' + number_before);
                    ct = 1;
                    number_before = result[i] - '0';
                }
            }
            temp.push_back('0' + ct);
            temp.push_back('0' + number_before);
            result = temp;
            n--;
        }
        return result;
    }
};