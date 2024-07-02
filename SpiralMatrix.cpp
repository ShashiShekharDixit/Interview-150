class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty())
        return {};
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> ans;
        ans.reserve(m * n);
        int r1 = 0, r2 = m - 1;
        int c1 = 0, c2 = n - 1;
        while(r1 <= r2 && c1 <= c2){
            for(int j = c1; j <= c2; ++j)
            ans.push_back(matrix[r1][j]);
            if(++r1 > r2) break;
            for(int i = r1; i <= r2; ++i)
            ans.push_back(matrix[i][c2]);
            if(--c2 < c1) break;
            for(int j = c2; j >= c1; --j)
            ans.push_back(matrix[r2][j]);
            if(--r2 < r1) break;
            for(int i = r2; i >= r1; --i)
            ans.push_back(matrix[i][c1]);
            if(++c1 > c2) break;
        }
        return ans;
    }
};