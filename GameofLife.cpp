#include <vector>
using namespace std;
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<pair<int, int>> directions = {{1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}};
        int rows = board.size();
        int cols = board[0].size();
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                int live = 0;
                for (auto dir : directions) {
                    int x = i + dir.first;
                    int y = j + dir.second;
                    if (x >= 0 && x < rows && y >= 0 && y < cols && abs(board[x][y]) == 1) {
                        live++;
                    }
                }
                if (board[i][j] == 1 && (live < 2 || live > 3)) {
                    board[i][j] = -1;  
                }
                if (board[i][j] == 0 && live == 3) {
                    board[i][j] = 2;   
                }
            }
        }
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (board[i][j] > 0) {
                    board[i][j] = 1; 
                } else {
                    board[i][j] = 0;  
                }
            }
        }
    }
};