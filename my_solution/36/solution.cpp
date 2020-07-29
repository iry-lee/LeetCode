class Solution {
public:
    int SUDOKU_LEN = 9;
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < SUDOKU_LEN; i++){
            int temp[9] = {0};
            for(int j = 0; j < SUDOKU_LEN; j++){
                if(board[i][j] != '.'){
                    int number = board[i][j]-'1';
                    if(temp[number] == 0) temp[number] = 1;
                    else return false;
                }
            }
        }
        for(int j = 0; j < SUDOKU_LEN; j++){
            int temp[9] = {0};
            for(int i = 0; i < SUDOKU_LEN; i++){
                if(board[i][j] != '.'){
                    int number = board[i][j]-'1';
                    if(temp[number] == 0) temp[number] = 1;
                    else return false;
                }
            }
        }
        for(int k = 0; k < SUDOKU_LEN; k+=3){
            for(int l = 0; l < SUDOKU_LEN; l+=3){
                int temp[9] = {0};
                for(int i = 0; i < 3; i++){
                    for(int j = 0; j < 3; j++){
                        if(board[k+i][l+j] != '.'){
                            int number = board[k+i][l+j] - '1';
                            if(temp[number] == 0) temp[number] = 1;
                            else return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};