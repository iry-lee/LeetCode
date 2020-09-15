// 官方方法更容易编程：先将矩阵转置，然后再翻转每一行
// 但是不容易想到
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // 转置
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        // 翻转行
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n/2; j++){
                int temp = matrix[i][j];
                matrix[i][j] = matrix[i][n-1-j];
                matrix[i][n-1-j] = temp;
            }
        }
    }
};


// 我的方法：模拟旋转
// 先从旋转四个角的数字开始，然后扩展到旋转这一行上除最后一个点之外的点，然后扩展到每一层上
// class Solution {
// public:
//     void func(vector<vector<int>>& matrix, int x, int y){
//         int val = matrix[x][y], n = matrix.size();
//         for(int i = 0; i < 4; i++){
//             int temp = matrix[y][n-1-x];
//             matrix[y][n-1-x] = val;
//             val = temp;
//             // 这里一定要注意，xy要想同时更新，一定要提前保存一下之前的x值
//             int old_x = x;
//             x = y; 
//             y = n-1-old_x;
//         }
//     }
//     void rotate(vector<vector<int>>& matrix) {
//         // 两层循环，第一层循环确定矩阵的层，第二层循环确定寻转点的位值
//         for(int i = 0; i < (int)matrix.size()/2; i++){
//             for(int j = i; j < (int)matrix.size()-1-i; j++) 
//                 func(matrix, j, i);
//         }
//     }  
// };

// 测试样例 1：
// [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
// 测试样例 2：
// [[1,2,3],[4,5,6],[7,8,9]]
// 测试样例 3：
// [[1,2,3,123,24,432,432,4],[4,5,6,12,3,12,3,23],[7,8,9,213,213,12,312,312],[12,56,4,7,4,577,7,5],[2315,56,756,756,75,6,7,75],[78,9,78,9,798,9,78,978],[45,6,54,74,5745,7,74,7],[373,73754,8,5,8,84,867,8]]

//