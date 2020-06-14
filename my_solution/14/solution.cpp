//
// Created by 11029 on 2020/6/12.
//
// 【垂直扫描】
//
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result;
        if(strs.empty())
            return result;
        for(int i = 0; i < strs[0].size(); i++){
            int flag = 1;
            char init = strs[0][i];
            for(int j = 1; j < strs.size(); j++){
                if(i >= strs[j].size() || strs[j][i] != init){
                    flag = 0;
                    break;
                }
            }
            if(flag){
                string part(1, init);
                result.append(part);
            }
            else{
                break;
            }
        }
        return result;
    }
};

/*
 * 【个人感想】
 * 这个题的解法是非常多的
 * 看官方的讲解就给出了很多种
 * 受到启发，想到了构造二叉树的方法
 * 先把第一个字符串输入进来
 * 然后再依次输入后面的。
 * 当后面的字符串添加到树的过程中，一旦要产生新的分支
 * 就停止，说明到此处已经不匹配了
 * 最后得到的 链表 就是最长公共子串。
 * */