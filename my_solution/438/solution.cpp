// 字母异位词可以使用一个长度为26的哈希表来表示
// 然后设置两个指针，维护一个滑动窗口，然后窗口内也设置一个
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int hash [26] = {0}, temphash[26] = {0};
        int ptr1 = 0, ptr2 = 0;
        vector<int> ans;
        if(p.size() > s.size()) return ans;
        for(char c : p) hash[c-'a']++;
        // ptr1先前进
        for(; ptr1 < p.size(); ptr1++) temphash[s[ptr1]-'a']++;
        // 开始滑动窗口
        for(; ptr1 <= s.size(); ptr1++, ptr2++){
            bool flag = true;
            for(int i = 0; i < 26; i++)
                if(hash[i] != temphash[i]){
                    flag = false;
                    break;
                }
            if(flag) ans.push_back(ptr2);
            // 严格一下边界条件
            if(ptr1 == s.size()) break;
            // 开始窗口滑动
            temphash[s[ptr2]-'a']--;
            temphash[s[ptr1]-'a']++;
        }
        return ans;
    }
};