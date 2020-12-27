// 根据每一行的第一个元素可以判断后续的元素在那儿
// 这个的时间复杂度为O(mlogn)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        if(n == 0) return false;
        if(matrix.size() == 1) return binary_search(matrix[0].begin(), matrix[0].end(), target);
        for(int i = 0; i < matrix.size(); i++){
            if(matrix[i].size() > 0){
                if(matrix[i][0] > target){
                    if(i == 0) break;
                    else{
                        return binary_search(matrix[i-1].begin(), matrix[i-1].end(), target);
                    }
                }
                else if(matrix[i][0] == target) return true;
            }
        }
        return binary_search(matrix[n-1].begin(), matrix[n-1].end(), target);
    }
};

// 时间复杂度为O(log(mn))的方法
// 将这个矩阵中的搜索当作是一维数组中的二分查找

