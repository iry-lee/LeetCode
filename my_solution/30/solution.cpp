// 注意题干里有一个条件，长度相同的单词words，假设长度为n
// 那这样的话，可以原字符串s分成一堆长度n的片段
// 这样的切分方式有n-1种
// 每种方式下，都去找是否有片段与words中的一个相同
// 这里可以使用hash来做
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int len = s.size();
        if(words.size() == 0){
            vector<int> v;
            if(len == 0){
                v.push_back(0);
                return v;
            }
            else return v;
        }
        
        int n = words[0].size();
        vector<int> res;
        // n-1种切分方式
        for(int i = 0; i < n; i++){
            int ct = 0;
            unordered_map<int, int> hash;
            for(int j = i; j < len; j+=n){
                // cout << j << endl;
                for(int k = 0; k < words.size(); k++){
                    // cout << s.substr(j, n) << " " << words[k] << endl;
                    if(s.substr(j, n) == words[k]){
                        if(hash.find(k) == hash.end()){
                            hash[k] = j;
                            ct++;
                        }
                        else{
                            for(auto ite = hash.begin(); ite != hash.end();){
                                auto temp = ite;
                                ite++;
                                if(temp->second < hash[k]) {
                                    hash.erase(temp->first);
                                    ct--;
                                }
                            }
                            hash[k] = j;
                        }
                        if(ct == words.size()){
                            res.push_back(j + n - ct*n);
                        }
                        break;
                    }
                }
            }
        }
        return res;
    }
};


/*
忘记考虑单词可能出现重复的问题了：
测试点：
"wordgoodgoodgoodbestword"
["word","good","best","good"]

*/