class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if(matrix.size() == 0 || matrix[0].size() == 0) return result;
        int upper = 0, buttom = (int)matrix.size()-1, left = 0, right = (int)matrix[0].size()-1;
        int i = 0, j = 0, ct = 0;
        while(result.size() < matrix.size()*matrix[0].size()){
            result.push_back(matrix[i][j]);
            if(i == upper){
                if(j == right) i++;
                else j++;
            }
            else if(j == right){
                if(i == buttom) j--;
                else i++;
            }
            else if(i == buttom){
                if(j == left) i--;
                else j--;  
            }
            else if(j == left){
                if(i == upper) j++;
                else i--;
            }

            if(i == ct && j == ct){
                ct++;
                i = j = ct;
                upper++;
                right--;
                left++;
                buttom--;
            }
        }
        return result;
    }
};