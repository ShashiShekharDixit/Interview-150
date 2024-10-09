class Solution {
private:
    int solveTabulation(vector<vector<int>> &triangle, int i, int j, int n)
    {
        vector<vector<int>> dp(n + 1, vector<int> (n + 1, 0));
        for(int i = 0; i < n; i++)
        {
            dp[n - 1][i] = triangle[n - 1][i];
        }
        for(int i = n - 1; i >= 0; i--)
        {
            int first = 0, second = 0;
            for(int j = i; j >= 0; j--)
            {
                first = triangle[i][j] + dp[i + 1][j];
                second = triangle[i][j] + dp[i + 1][j + 1];
                dp[i][j] = min(first, second);
            }
        }
        return dp[0][0];
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int ans = solveTabulation(triangle, n - 1, n - 1, n);
        return ans;
    }
};