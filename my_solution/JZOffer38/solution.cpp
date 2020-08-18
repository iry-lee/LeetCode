#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    void func(vector<string> &result, string subresult, int ct[], int n){
        vector<char> charSet;
        if(n == 0){
            result.push_back(subresult);
            return;
        }
        for(int i = 0; i < 128; i++){
            if(ct[i] > 0) charSet.push_back(i);
        }
        for(int i = 0; i < charSet.size(); i++){
            string temp = subresult;
            temp.append(1, charSet[i]);
            ct[charSet[i]]--;
            func(result, temp, ct, n-1);
            ct[charSet[i]]++;
        }
    }
    vector<string> permutation(string s) {
        vector<string> result;
        if(s.size() == 0){
            result.push_back("");
            return result;
        }

        int ct [128] = {0};
        for(int i = 0; i < s.size(); i++){
            ct[s[i]]++;
        }

        func(result, "", ct, s.size());

        return result;
    }
};