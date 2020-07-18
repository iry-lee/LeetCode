class Solution {
public:
    struct rectangle{
        //         A_______________
        //         |               |
        //         |_______________|
        //                         B
        int ax;
        int ay;
        int bx;
        int by;
    };
    bool findNumberInRect(vector<vector<int>> &matrix, rectangle rect, int target){
        int m = matrix.size(), n = matrix[0].size();
        int x = (rect.ax + rect.bx)/2, y = (rect.ay + rect.by)/2;
        // 处理不是形状的情况。
        if(rect.ax > rect.bx || rect.ay > rect.by
                || x < 0 || x >= m || y < 0 || y >= n) return false;
        // 处理是一个点的情况。如果这个矩形的长和宽都为1的时候，直接判断当前值是否与target相等
        if(rect.ax == rect.bx && rect.ay == rect.by) return matrix[x][y] == target;
        // 处理是矩形的情况。
        //cout << matrix[x][y] << "\n";
        if(matrix[x][y] == target) return true;
        else if(matrix[x][y] > target){
            rectangle r1 = {rect.ax, rect.ay, x-1, rect.by};
            rectangle r2 = {x, rect.ay, rect.bx, y-1};
            return findNumberInRect(matrix, r1, target)
                   || findNumberInRect(matrix, r2, target);
        }
        else{
            rectangle r1 = {rect.ax, y+1, x, rect.by};
            rectangle r2 = {x+1, rect.ay, rect.bx, rect.by};
            return findNumberInRect(matrix, r1, target)
                   || findNumberInRect(matrix, r2, target);
        }
    }
    bool findNumberIn2DArray(vector<vector<int>> &matrix, int target) {
        if(matrix.empty()) return false;
        if(matrix[0].empty()) return false;
        int m = matrix.size(), n = matrix[0].size();
        rectangle rect = {0, 0, m, n};
        return findNumberInRect(matrix, rect, target);
    }
};