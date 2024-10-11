#include <vector>
using namespace std;
class Solution {
public:
    int rat(vector<vector<int>>& a, int m, int n, int i, int j, vector<vector<int>>& dp) {
        if (i == m - 1 && j == n - 1  && a[i][j] != 1) {
            return 1;
        }
        if (i >= m || j >= n || a[i][j] == 1 || a[m-1][n-1] == 1) {
            return 0;
        }
        if (dp[i][j] != -5) {
            return dp[i][j];
        }
       
        int right = rat(a, m, n, i, j + 1, dp); 
        int down = rat(a, m, n, i + 1, j, dp); 
        dp[i][j] = right + down;
        return right + down;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -5)); 
        int result = rat(obstacleGrid, m, n, 0, 0, dp);
        return result;
    }
};