class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix (n , vector<int>(n, 0));

        // 用左上角的点A和右下角的点B，确定两个边界
        int num = n * n;
        int x = 0, y = 0;
        int ax = 0, ay = 0, bx = n-1, by = n-1;
        for(int i = 1; i <= num;){
            // 可以嵌套四个并列的while循环
            // 在顶部行 向右
            while(x == ax && y <= by)
                matrix[x][y++] = i++;
            ax++;
            y--;
            x++;
            // 在右侧列 向下
            while(x <= bx && y == by)
                matrix[x++][y] = i++;
            by--;
            x--;
            y--;
            // 在底部行 向左
            while(x == bx && y >= ay)
                matrix[x][y--] = i++;
            bx--;
            y++;
            x--;
            // 在左侧列 向上
            while(x >= ax && y == ay)
                matrix[x--][y] = i++;
            ay++;
            x++;
            y++;
        }
        return matrix;
    }
};