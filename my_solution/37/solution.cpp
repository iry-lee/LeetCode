// 递归回溯
// 方法一、哈希表+递归回溯，运行用时80ms
// 看了一眼问题考察的知识点，知道了这个题考察的是回溯和哈希
// 大的框架当然使用的是回溯，然后需要建立3x9个哈希表：
// 九个哈希表对应9个行
// 九个哈希表对应9个列
// 九个哈希表对应9个3x3的格子
/*
class Solution {
private:
    static const int Len = 9;
    unordered_set<int> hashTable [3][Len];
public:
    bool dfs(vector<vector<char>>& board){
        // 先找到可以填入值的位置
        int ti = -1, tj = -1;
        for(int i = 0; i < Len; i++){
            for(int j = 0; j < Len; j++){
                if(board[i][j] == '.') {
                    ti = i; 
                    tj = j;
                    break;
                }
            }
        }
        if(ti == -1 && tj == -1) return true;
        else{
            // 尝试在这个位置填入一个值
            int res = false;
            for(int i = 1; i <= Len; i++){
                if(hashTable[0][ti].find(i) == hashTable[0][ti].end()
                        && hashTable[1][tj].find(i) == hashTable[1][tj].end()
                        && hashTable[2][ti/3 * 3 + tj/3].find(i) == hashTable[2][ti/3 * 3 + tj/3].end()){
                    // 插入哈希表
                    hashTable[0][ti].insert(i);
                    hashTable[1][tj].insert(i);
                    hashTable[2][ti/3 * 3 + tj/3].insert(i);
                    board[ti][tj] = i + '0';
                    res = dfs(board);
                    if(res == false) {
                        board[ti][tj] = '.';
                        hashTable[0][ti].erase(i);
                        hashTable[1][tj].erase(i);
                        hashTable[2][ti/3 * 3 + tj/3].erase(i);
                    }
                    else return res;
                }
            }
            return res;
        }
    }
    void solveSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < Len; i++){
            for(int j = 0; j < Len; j++){
                if(board[i][j] == '.') continue;
                // 填第一种哈希表：行哈希
                hashTable[0][i].insert(board[i][j] - '0');
                // 填第二种哈希表：列哈希
                hashTable[1][j].insert(board[i][j] - '0');
                // 填第三种哈希表：小正方形哈希
                hashTable[2][i/3 * 3 + j/3].insert(board[i][j] - '0');
            }
        }
        dfs(board);
    }
};
*/
// 该方法的问题，明明哈希的时候，只有9种可能性，为此建一个unordered_set有点杀鸡用牛刀了
// 就不再这里用长度为9的数组对它进行优化了，后面直接用位运算的方法优化。
// 而且我在做dfs的时候，也要传递一下当前遍历到了矩阵中的哪一个位置，防止层层再从头遍历

// 方法二、位哈希+回溯+递归函数优化，运行用时4ms
class Solution{
private:
    const static int Length = 9;
    int rows[Length] = {0}, cols[Length] = {0}, square[Length] = {0};
    bool endFlag = false;
    
public:
    void dfs(vector<vector<char>>& board, int x, int y){
        if(x == Length && y == 0) {
            endFlag = true; 
            return;
        }
        else if(board[x][y] != '.'){
            if(y < Length-1) dfs(board, x, y+1);
            else if(y == Length-1) dfs(board, x+1, 0);
        }
        else{
            for(int i = 1; i <= 9; i++){
                // cout << rows[x] << " " << (1 << i) << endl;
                if((rows[x] & (1 << i)) == 0 
                        && (cols[y] & (1 << i)) == 0
                        && (square[x/3 * 3 + y/3] & (1 << i)) == 0){
                    // 更新位哈希
                    rows[x] += (1 << i);
                    cols[y] += (1 << i);
                    square[x/3 * 3 + y/3] += (1 << i);
                    // 更新数独
                    board[x][y] = '0' + i;
                    if(y < Length-1) dfs(board, x, y+1);
                    else dfs(board, x+1, 0);
                    if(endFlag) return;
                    // 回退数独
                    board[x][y] = '.';
                    // 回退哈希
                    rows[x] -= (1 << i);
                    cols[y] -= (1 << i);
                    square[x/3 * 3 + y/3] -= (1 << i);
                }
           }
        }
    }
    void solveSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < Length; i++){
            for(int j = 0; j < Length; j++){
                if(board[i][j] == '.') continue;
                // 填第一种哈希表：行哈希
                rows[i] += (1 << (board[i][j] - '0'));
                // 填第二种哈希表：列哈希
                cols[j] += (1 << (board[i][j] - '0'));
                // 填第三种哈希表：小正方形哈希
                square[i/3 * 3 + j/3] += (1 << (board[i][j] - '0'));
            }
        }
        dfs(board, 0, 0);
    }
};
