class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        set<int> visited;
        auto getPos = [&](int pos) {
            int row = (pos - 1) / n;
            int col = (pos - 1) % n;
            if (row % 2 == 1) col = n - 1 - col;
            row = n - 1 - row;
            return make_pair(row, col);
        };
        queue<pair<int, int>> q;
        q.push({1, 0});

        while (!q.empty()) {
            auto [pos, moves] = q.front();
            q.pop();

            for (int i = 1; i < 7; ++i) {
                int newPos = i + pos;
                auto [r, c] = getPos(newPos);

                if (board[r][c] != -1) newPos = board[r][c];
                if (newPos == n * n) return moves + 1;

                if (!visited.count(newPos)) {
                    visited.insert(newPos);
                    q.push({newPos, moves + 1});
                }
            }
        }
        return -1;
    }
};