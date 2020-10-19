// 【哈希】（题解中的暴力求解法）
// 求往后多少步，能找到一个比当前大的数字
// 暴力解法时间复杂度为O(n^2)：对于当前数字直接遍历其后面的所有数字，找到一个比当前数字大的为止
// 感觉会有O(nlogn)的方法
// 如果倒着往前怎么样
// 说了范围是[30,100]，哈希？用哈希的话，时间复杂度是O(n)
/*
class Solution {
private:
    int MAX_TEMP = 100;
    int MIN_TEMP = 30;
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        if(T.size() == 0) return T;
        int len = T.size();
        int hashtable[MAX_TEMP-MIN_TEMP+1];
        memset(hashtable, -1, sizeof(hashtable));
        vector<int> res(len);
        for(int i = len-1; i >= 0; i--){
            if(i == len-1) res[i] = 0;
            else{
                int minposi = INT_MAX;
                for(int j = T[i]-MIN_TEMP+1; j <= MAX_TEMP-MIN_TEMP; j++)
                    if(hashtable[j] != -1 && minposi > hashtable[j]) 
                        minposi = hashtable[j];
                if(minposi == INT_MAX) res[i] = 0;
                else res[i] = minposi-i;
            }
            hashtable[T[i]-MIN_TEMP] = i;
        }
        return res;
    }
};
*/

// 【单调栈】题解中给出的更好的方法
// 栈里存的是下标
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T){
        vector<int> ans;
        stack<int> st;  // 单调栈中存放的是下标
        int len = T.size();
        // 先初始化为全0
        for(int i = 0; i < len; i++) ans.push_back(0);
        // 然后开始操作起来
        for(int i = 0; i < len; i++){
            int temp = T[i];
            while(!st.empty() && temp > T[st.top()]){
                // 更新ans
                ans[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};