// 找联通的1的个数？
// 只需要遍历整个矩阵一遍，如果找到一个1，就开始向其上下左右递归搜索与之连通的1，将其全部置为0

class Solution {
public:
    struct Point{
        int x;
        int y;
    };

    void accessLand(Point p, vector<vector<char>>& grid, int m, int n){
        // 上
        if(p.x - 1 >= 0 && grid[p.x-1][p.y] == '1'){
            grid[p.x-1][p.y] = '0';
            accessLand({p.x-1, p.y}, grid, m, n);
        } 
        // 下
        if(p.x + 1 < m && grid[p.x+1][p.y] == '1'){
            grid[p.x+1][p.y] = '0';
            accessLand({p.x+1, p.y}, grid, m, n);
        }
        // 左
        if(p.y - 1 >= 0 && grid[p.x][p.y-1] == '1'){
            grid[p.x][p.y-1] = '0';
            accessLand({p.x, p.y-1}, grid, m, n);
        }
        // 右
        if(p.y + 1 < n && grid[p.x][p.y+1] == '1'){
            grid[p.x][p.y+1] = '0';
            accessLand({p.x, p.y+1}, grid, m, n);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n;
        if(m == 0) return 0;
        n = grid[0].size();
        if(n == 0) return 0;

        int res = 0, i = 0;
        for(; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1'){
                    res++;
                    grid[i][j] = '0';
                    // 这个后面是去找与之连通的其他点
                    // 将与这个点连通的所有点都置为0
                    accessLand({i, j}, grid, m, n);
                }
            }
        }
        return res;
    }
};