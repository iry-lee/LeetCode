//
// Created by 11029 on 2020/6/12.
//

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        // 存储0-9对应的字母，当然0跟1是没有用的
        string table [10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        // 还没想好这里怎么处理
        for(int i = 0; i < digits.size(); i++){  //先是对于输入的数字字符串，取一个数字
            if(i == 0){ //初始化
                for(int j = 0; j < table[digits[i] - '0'].size(); j++) {
                    string temp(1, table[digits[i] - '0'][j]);
                    result.push_back(temp);
                }
            }
            else{
                //提前存下result的size
                int size = result.size();
                for(int j = 0; j < table[digits[i] - '0'].size(); j++) {
                    if (j == table[digits[i] - '0'].size() - 1) {
                        // 不到最后一个的时候，都只是添加新的字符串，
                        // 到最后一个的时候才修改原有的字符串
                        for (int k = 0; k < size; k++) //对于每个之前的字符，都要加上新的字符在后面
                            result[k] = result[k].append(1, (char) table[digits[i] - '0'][j]);
                        }
                    else{
                        //之前的几个都是为result增加新的字符串，
                        for (int k = 0; k < size; k++) { //对于每个之前的字符，都要加上新的字符在后面
                            string temp = result[k];
                            result.push_back(temp.append(1, (char) table[digits[i] - '0'][j]));
                        }
                    }
                }
            }
        }
        return result;
    }
};