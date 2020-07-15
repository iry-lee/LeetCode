//
// Created by 11029 on 2020/6/12.
//
#include <cstring>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int lwindow = needle.size(), a = 26;
        long long ONE = 1, modulus = ONE << 31, needle_hash = 0, haystack_hash = 0;
        for(int i = 0; i < lwindow; i++){
            needle_hash = (needle_hash*a + needle[i] - 'a') % modulus;
        }
        if(needle_hash < 0) needle_hash += modulus;
        // hash匹配上以后，有可能真实值不一样，这是所谓的哈希碰撞
        // 所以为了正确起见还是要检查一下匹配的正确性，但这里先省略一下
        if(haystack.size() < lwindow) return -1;
        else{
            long long b = 1;   // 保存 a^(lwindow-1) 的值
            for(int i = 0; i < lwindow; i++){
                haystack_hash = (haystack_hash * a + haystack[i] - 'a') % modulus;
                if(i > 0) {
                    b *= a;
                    b %= modulus;
                }
            }
            if(haystack_hash == needle_hash) return 0;
            for(int i = lwindow; i < haystack.size(); i++){
                haystack_hash = (haystack_hash -  (haystack[i-lwindow] - 'a') * b) % modulus;
                haystack_hash = (haystack_hash * a + haystack[i] - 'a') % modulus;
                if(haystack_hash < (long)0) haystack_hash += modulus;
                if(haystack_hash == needle_hash) return i - lwindow + 1;
            }
            return -1;
        }
    }
};
/*
 方法一、滑动窗口
 每次将窗口内的字符串与目标字串作比较
 方法二、双指针
    int strStr(string haystack, string needle) {
        if(needle.size() == 0) return 0;
        if(haystack.size() == 0) return -1;
        int i = 0, j = 0; // i对应needle，j对应haystack
        while(j < haystack.size()){
            if(needle[i] == haystack[j]){
                i++; j++;
                if(i == needle.size()) return j-i;
            }
            else{
                if(i != 0){
                    j = j - i + 1;
                    i = 0;
                }
                else j++;
            }
        }
        return -1;
    }
 可以优化的点在于，每次从haystack中，与needle[0]相同的位置开始匹配
 下面的KMP其实也实现了这一优化，而且更进一步优化了
 方法三、KMP算法
int strStr(string haystack, string needle) {
        if(needle.empty()) return 0;
        if(haystack.empty()) return -1;
        int i = 1, j = 0; // i对应needle，j对应haystack
        // 生成转移状态数组
        int jump [(int)needle.size()];
        memset(jump, 0, (int)needle.size() * sizeof(int));
        while(i < needle.size()){
            if(needle[i] != needle[j]){
                if(j == 0) i++;
                else j = jump[j - 1];
            }
            while (needle[i] == needle[j] && i < needle.size()){
                jump[i] = j + 1;
                j++; i++;
            }
        }

        // 开始匹配
        i = 0; j = 0;
        while(j < haystack.size()){
            if(haystack[j] == needle[i]){
                i++; j++;
                if(i == needle.size()) return j-i;
            }
            else{
                if(i != 0){
                    i = jump[i-1];
                }
                else j++;
            }
        }
        return -1;
    }
 在学数据结构的时候学到一种方法，先对needle生成一个转移状态数组
 就可以知道在某一个位置匹配失败以后，下一步跳转到什么位置
 方法四、哈希 Rabin Karp
 【注意】Linux 64位下的long的长度(64位)与windows 64位下的long长度(32位)不一样，所以要么用int，要么用 long long
 思路与滑动窗口有点类似，但是比较的是滑动窗口内的字符串的哈希值与目标字符串的哈希值
 需要注意的一点是，哈希值有可能会很大，所以要对其取模
 int strStr(string haystack, string needle) {
        int lwindow = needle.size(), a = 26;
        long long ONE = 1, modulus = ONE << 31, needle_hash = 0, haystack_hash = 0;
        for(int i = 0; i < lwindow; i++){
            needle_hash = (needle_hash*a + needle[i] - 'a') % modulus;
        }
        if(needle_hash < 0) needle_hash += modulus;
        // hash匹配上以后，有可能真实值不一样，这是所谓的哈希碰撞
        // 所以为了正确起见还是要检查一下匹配的正确性，但这里先省略一下
        if(haystack.size() < lwindow) return -1;
        else{
            long long b = 1;   // 保存 a^(lwindow-1) 的值
            for(int i = 0; i < lwindow; i++){
                haystack_hash = (haystack_hash * a + haystack[i] - 'a') % modulus;
                if(i > 0) {
                    b *= a;
                    b %= modulus;
                }
            }
            if(haystack_hash == needle_hash) return 0;
            for(int i = lwindow; i < haystack.size(); i++){
                haystack_hash = (haystack_hash -  (haystack[i-lwindow] - 'a') * b) % modulus;
                haystack_hash = (haystack_hash * a + haystack[i] - 'a') % modulus;
                if(haystack_hash < (long)0) haystack_hash += modulus;
                if(haystack_hash == needle_hash) return i - lwindow + 1;
            }
            return -1;
        }
    }
*/
/*
测试样例：
"acedcabcdddabcdddabe"
"abcdddabe"

*/

// main.cpp
//
//#include <iostream>
//#include <cstdio>
//#include "utils.h"
//# include "my_solution/29/solution.cpp"   // 这里如果想跑哪一个题目的话，只要把中间的那个题号改掉就可以了
//
//int main() {
//    // 输入重定向，现在有点问题
//    // freopen("input.txt","r", stdin);
//
//    char c;
//    Solution solution;  // 实例化题解文件中的类
//    string s1 = utils::getString();
//    string s2 = utils::getString();
//    cout << solution.strStr(s1, s2);
//
//    return 0;
//}