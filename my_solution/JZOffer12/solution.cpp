#include <memory.h>
#include <stack>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    struct point{
        int x;
        int y;
        int ptr;
    };
    bool exist(vector<vector<char>>& board, string word) {
        if(board.size() == 0 || board[0].size() == 0) return false;
        int map [board.size()][board[0].size()];
        memset(map, 1, sizeof(int)*board.size()*board[0].size());
        // 如果 map[i][j] == 0 表示这个格子就不能进了
        stack<point> root, path;
        int wordptr = 0;
        // 把所有的等于字符串的第一个字符的都入栈
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] == word[0]) {
                    root.push({i, j, 0});
                    wordptr = 1;
                }
            }
        }
        if(wordptr == 0) return false;
        wordptr = 0;
        // 对于栈顶的元素，按照上下左右的顺序，看它周围是否是满足下一个字符的元素
        while(!root.empty()){
            point top = root.top();
            wordptr = top.ptr + 1;
            // 一个点的周边节点想要进栈，这个点就要从栈里出来，周边节点进栈
            root.pop();
            // 处理一下path栈，如果有回溯的话，path要释放占用的位置
            while(!path.empty() && path.top().ptr >= wordptr-1){
                point temp = path.top();
                map[temp.x][temp.y] = 1;
                path.pop();
            }
            path.push(top);
            // 把这个点标记为已经访问的
            map[top.x][top.y] = 0;
            if(wordptr == word.size()) return true;
            int ct = 0;
            // 这里改成候选项都逐一进栈
            // 上
            if((top.x - 1) >= 0 && map[top.x-1][top.y]
                    && word[wordptr] == board[top.x-1][top.y]){
                root.push({top.x - 1, top.y, wordptr});
                ct++;
            }
            // 下
            if ((top.x + 1) < board.size() && map[top.x+1][top.y]
                    && word[wordptr] == board[top.x+1][top.y]){
                root.push({top.x + 1, top.y, wordptr});
                ct++;
            }
            // 左
            if ((top.y - 1) >= 0 && map[top.x][top.y-1]
                    && word[wordptr] == board[top.x][top.y-1]){
                root.push({top.x, top.y-1, wordptr});
                ct++;
            }
            // 右
            if ((top.y + 1) < board[0].size() && map[top.x][top.y + 1]
                && word[wordptr] == board[top.x][top.y+1]){
                root.push({top.x, top.y+1, wordptr});
                ct++;
            }

            if(ct == 0){    // 如果这个点的后面没有可选的项
                map[top.x][top.y] = 1;
                path.pop();
            }
        }
        return false;
    }
};
/*
[["a","a"]]
"aaa"
*/
// 这个测试点出问题的原因是，它会重复尝试之前失败过的选项
// 所以这里还是需要栈的
// 这个题是不是得想一下，八皇后

/*
[["z", "b", "z"],["b","a","b"],["z","b","c"]]
"abc"
*/

/*
[["a"]]
"a"
*/

/*
[["F","Y","C","E","N","R","D"],["K","L","N","F","I","N","U"],["A","A","A","R","A","H","R"],["N","D","K","L","P","N","E"],["A","L","A","N","S","A","P"],["O","O","G","O","T","P","N"],["H","P","O","L","A","N","O"]]
"POLAND"
*/

/*
[["A","B","C","E"],["S","F","E","S"],["A","D","E","E"]]
"ABCESEEEFS"
*/
// 这个测试点出问题的原因是，回溯的时候，之前的点也要把所占据，所设为0的恢复成1

// main.cpp
//#include <iostream>
//#include <cstdio>
//#include "utils.h"
//#include "my_solution/JZOffer12/solution.cpp"   // 这里如果想跑哪一个题目的话，只要把中间的那个题号改掉就可以了
//
//int main() {
//
//    Solution solution;  // 实例化题解文件中的类
//
//    vector<char> c1 = {'A','B','C','E'};
//    vector<char> c2 = {'S','F','E','S'};
//    vector<char> c3 = {'A','D','E','E'};
//    vector<vector<char>> vvc = {c1, c2, c3};
//
//    cout << solution.exist(vvc, "ABCESEEEFS");
//
//    return 0;
//}