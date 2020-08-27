// 是不是得用动态规划，无脑递归复杂度应该会不低
// 所以要倒着来：
// 最后一个字符，1种情况
// 最后两个字符，1/2种情况
// 最后三个字符，...
class Solution {
public:
    int translateNum(int num) {
        string snumber = to_string(num);
        int len = snumber.size();
        int record [len+1];  // 倒数
        record[0] = 1;
        record[1] = 1;
        for(int i = 2; i < len + 1; i++){
            record[i] = record[i-1];
            if(snumber[len - i] == '1' 
                || (snumber[len - i] == '2' && snumber[len - i+1] < '6'))
                record[i] += record[i-2];
        }
        return record[len];
    }
};