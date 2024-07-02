class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        int rowcase[9][9] = {0};
        int colcase[9][9] = {0};
        int gridcase[9][9] = {0};
        for(int i = 0; i < m ; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] != '.'){
                    int num = board[i][j]-'0';
                    int k = i/3*3 + j/3;
                    if(rowcase[i][num-1]++||colcase[j][num-1]++ || gridcase[k][num-1]++)
                    return false;
                }
            }
        }
        return true;
    }
};