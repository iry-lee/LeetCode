// 动态规划
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0) return 0;
        int n = matrix.size(), m = matrix[0].size();
        int dpmatrix[n][m];
        int res = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == '0') dpmatrix[i][j] = 0;
                else{
                    // n1是左上，n2是左边，n3是正上                    
                    int n1 = 0, n2 = 0, n3 = 0;
                    if(i-1 >= 0 && j-1 >= 0) n1 = dpmatrix[i-1][j-1];
                    if(j-1 >= 0) n2 = dpmatrix[i][j-1];
                    if(i-1 >= 0) n3 = dpmatrix[i-1][j];
                    dpmatrix[i][j] = min(min(n1, n2),n3) + 1;
                    if(dpmatrix[i][j] > res) res = dpmatrix[i][j];
                }
            }
        }
        return res*res;
    }
};

// 看到题目以后的一些直观想法：
// 暴力求解方法是，面积从大到小，依次遍历所有的可能的矩阵，判断这个矩阵中的元素是否全为1
// 此外
// 可以假设遍历到的1就是目标矩阵的最左上方的那个1，然后以这个1为种子，往右往下遍历
// 感觉依旧可以优化
// 总的来说，想要解决编程问题，就要找到一个合适的模型，一种满足一般规律的模型
// 一般来说模型要简洁
// 是不是可以沿着对角线找，先确定对角线上的1是存在的可靠的，然后再在其所在的行和列上找
// 所以一直可以沿着对角线找？
// 以及可不可以通过求解子问题找到原问题的解

// 有点没有思路，然后看了一下相关标签，发现是一个动态规划题
// 动态规划的话，看来仍旧是分解成子问题然后再做