// dp
// 本题的最优解的最大值就是26，也就是说，dp的其中一个维度的最大值就是26
// 字符串中最多也只出现26个字母，于是可以用32位的int来存储
class Solution {
private:
    const int Size = 26;
public:
    int countOne(int a){
        int ct = 0;
        while(a != 0){
            a = a & (a-1);
            ct++;
        }
        return ct;
    }

    int maxLength(vector<string>& arr) {
        int size = arr.size();
        vector<int> newarr;
        // 将字符串存储转换为int其实只用到26位
        for(int i = 0; i < size; i++){
            int val = 0;
            for(char c : arr[i]){
                int bit = 1 << (c - 'a');
                // (val & bit) == 0 说明这个字母在这个单词中目前没有出现过
                if((val & bit) == 0){
                    val += bit;
                }
                // 如果这个字母在这个单词中已经出现过，这个就没用了
                else{
                    val = 0;
                    break;
                }
            }
            if(val != 0) newarr.push_back(val);
        }
        
        // 建立dp数组
        vector<vector<int>> dp (Size);
        for(int i = 0; i < newarr.size(); i++){
            int ct = countOne(newarr[i]);
            // 先看看可不可以将自己加在别的字符串后面
            for(int j = Size-1; j >= 0; j--){
                for(int k = 0; k < dp[j].size(); k++){
                    if((newarr[i] & dp[j][k]) == 0){
                        dp[j+ct].push_back(newarr[i]+dp[j][k]);
                    }
                }
            }
            // 再把自己插进去
            dp[ct-1].push_back(newarr[i]);
        }
        
        for(int i = Size-1; i >= 0; i--){
            if(dp[i].size() >= 1) return i+1;
        }
        return 0;
    }
};