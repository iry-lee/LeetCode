// 本题最简单的方法就是递归，会有很多重复计算
// 那么就可以使用动态规划
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        if(n == 0) return 0;
        for(int i = n-2; i >= 0; i--){
            for(int j = 0; j < triangle[i].size(); j++){
                triangle[i][j] += min(triangle[i+1][j], triangle[i+1][j+1]);
            }
        }
        return triangle[0][0];
    }
};