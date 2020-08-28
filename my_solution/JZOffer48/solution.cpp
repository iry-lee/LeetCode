// 【哈希-改进版】
// 我是每次找到一个无重复字符串的时候，都把hash表清空
// 看到剑指offer上的方法其实还可以有更简单的方法：只需要认为这个hash表存放的是该字符上一次出现的位置
// 而且我之前使用的哈希算法还要回跳i，就使得时间复杂度变高。而这个方法直接通过修改ct就能够实现相应的功能
class Solution {
public:
    int lengthOfLongestSubstring(string s){
        int hash[128] = {0}; // 初始化为0，位置从1开始计数
        int max = 0, ct = 0;
        for(int i = 0; i < s.size(); i++){
            if(hash[s[i]] == 0 || hash[s[i]] - 1 < i - ct){ // 要么没有出现过，要么就不在当前这个字串里
                hash[s[i]] = i + 1;
                ct++;
                if(ct > max) max = ct;
            }
            else{
                // 这个时候应该改ct不用改i
                char ch = s[i];
                ct = i + 1 - hash[s[i]];
                hash[ch] = i + 1;
            }
        }
        return max;
    }
};

// 测试样例：
// "anviaj"
// 【哈希】
// 其实这就算是动态规划
// 这里找无重复字符，是不是可以考虑一下使用哈希
// 而且，如果出现了重复字符，可以通过哈希表记录之前的字符所在的位置，然后实现状态的转移
// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         // hash表初始化为全0，其中的值存放的是其在string s中第一次出现的位置，s的位置从1开始计数
//         int hash [128] = {0};
//         int max = 0, ct = 0;
//         for(int i = 0; i < s.size(); i++){
//             if(hash[s[i]] == 0){
//                 hash[s[i]] = i + 1;
//                 ct++;
//                 if(ct > max) max = ct;
//             }
//             else{
//                 i = hash[s[i]];
//                 memset(hash, 0, sizeof(hash));
//                 hash[s[i]] = i + 1;
//                 ct = 1;
//             }
//         }
//         return max;
//     }
// };

// 【滑动窗口】
// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         int h = 0, e = 1, max = 0;
//         for (int i = 1; i < s.size(); i++)
//         {
//             for (int j = h; j < e; j++)
//             {
//                 if(s[i] == s[j])
//                 {
//                     h = j + 1;
//                     break;
//                 }
//             }
//             e = i + 1;
//             if (e - h > max)
//                 max = e - h;
//             if (s.size() - h < max)
//                 break;
//         }
//         if (s.size() == 1)
//             max = 1;
//         return max;
//     }
// };