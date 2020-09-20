// 参考62，从右下角开始分别沿向上更新列，以及沿向左更新行
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.empty() || grid[0].empty()) return 0;
        int m = grid.size(), n = grid[0].size();
        int pointx = m - 1, pointy = n-1;
        while(pointx >= 0 && pointy >= 0){
            int temp = pointy;
            // 处理行
            while(temp >= 0){
                if(pointx + 1 >= m && temp + 1 >= n){}
                else if(pointx + 1 >= m) grid[pointx][temp] += grid[pointx][temp+1];
                else if(temp + 1 >= n) grid[pointx][temp] += grid[pointx+1][temp];
                else grid[pointx][temp] += min(grid[pointx+1][temp], grid[pointx][temp+1]);
                temp--;
            }
            temp = pointx-1;
            // 处理列
            while(temp >= 0){
                if(temp + 1 >= m && pointy + 1 >= n){}
                else if(temp + 1 >= m) grid[temp][pointy] += grid[temp][pointy+1];
                else if(pointy + 1 >= n) grid[temp][pointy] += grid[temp+1][pointy];
                else grid[temp][pointy] += min(grid[temp][pointy+1], grid[temp+1][pointy]);
                temp--;
            }
            pointx--;
            pointy--;
        }
        return grid[0][0];
    }
};