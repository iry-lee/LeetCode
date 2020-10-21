// 注意方括号有嵌套
// 是不是可以递归求解，中括号内的部分算作是一个子数组
class Solution {
public:
    string decodeString(string s) {
        string substr, ans;
        int bracketCt = 0, num = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] >= '0' && s[i] <= '9'){
                // 得到数字的起止位置
                int numBegin = i;
                while(s[i] != '[') i++;
                i++;
                // 初始化子串
                bracketCt = 1;
                substr = "";
                string strNum = s.substr(numBegin, i);
                num = stoi(strNum);
                // 填入字串
                while(bracketCt > 0){
                    if(!(s[i] == ']' && bracketCt == 1)) substr.append(1,s[i]);
                    if(s[i] == '[') bracketCt++;
                    else if(s[i] == ']')bracketCt--;
                    i++;
                }
                i--;
                // 递归求解
                substr = decodeString(substr);
                for(int j = 0; j < num; j++)
                    for(char c : substr) ans.append(1, c);
            }
            else ans.append(1, s[i]);
        }
        return ans;
    }
};