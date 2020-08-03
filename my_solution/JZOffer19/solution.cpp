class Solution {
public:
    struct star{
        int s_position;
        int p_position;
        int len;
    };
    bool isMatch(string s, string p) {
        if(s.empty() && p.empty() || !s.empty() && p.empty()) return true;
        if(s.empty() && !p.empty()) return false;
        stack<star> st;
        int sptr = 1, pptr = 1;
        while (1){
            while(1){
                if(pptr < p.size() && p[pptr] == '*'){
                    if(p[pptr-1] == '.'){  // .*的形式
                        // 直接先把s剩下的部分都扔进来
                        // 长度是多少？
                        star stemp = {sptr, pptr, (int)s.size() - sptr};
                        st.push(stemp);
                        break;
                    }
                    else{  // a*的形式

                    }
                }
                else{
                    if(s[sptr-1] == p[pptr-1]){
                        sptr++; pptr++;
                        if(sptr > s.size() || pptr > p.size()) break;
                    }
                    else if(p[pptr-1] == '.'){
                        sptr++; pptr++;
                        if(sptr > s.size() || pptr > p.size()) break;
                    }
                    else break;
                }
            }
            // 通过判断sptr与pptr的关系来判断是否匹配成功
            if(sptr < (int)s.size() - 1 || pptr < (int)p.size() - 1){
                // 没有匹配成功，需要操作st，并修改sptr和pptr
            }
            else break;
        }

    }
};