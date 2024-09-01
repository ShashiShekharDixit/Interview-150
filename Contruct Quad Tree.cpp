class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        int val = grid[0][0];
        bool splitQuad = false;
        for(vector<int>& v : grid){
            for(int& i : v){
                cout << i << ", ";
                if(i == val) continue;
                splitQuad = true;
                break;
            }
            cout << endl;
            if(splitQuad) break;
        }
        Node * root = new Node(splitQuad ? 1 : val, !splitQuad);
        if(splitQuad){
            vector<vector<int>> topLeft;
            for(int i = 0; i < grid.size()/2; i++){
                vector<int> v;
                for(int j = 0; j < grid.size()/2; j++){
                    v.push_back(grid[i][j]);
                }
                topLeft.push_back(v);
            }
            root->topLeft = construct(topLeft);
            vector<vector<int>> topRight;
            for(int i = 0; i < grid.size()/2; i++){
                vector<int> v;
                for(int j = grid.size()/2; j < grid.size(); j++){
                    v.push_back(grid[i][j]);
                }
                topRight.push_back(v);
            }
            root->topRight = construct(topRight);
            vector<vector<int>> bottomLeft;
            for(int i = grid.size()/2; i < grid.size(); i++){
                vector<int> v;
                for(int j = 0; j < grid.size()/2; j++){
                    v.push_back(grid[i][j]);
                }
                bottomLeft.push_back(v);
            }
            root->bottomLeft = construct(bottomLeft);
            vector<vector<int>> bottomRight;
            for(int i = grid.size()/2; i < grid.size(); i++){
                vector<int> v;
                for(int j = grid.size()/2; j < grid.size(); j++){
                    v.push_back(grid[i][j]);
                }
                bottomRight.push_back(v);
            }
            root->bottomRight = construct(bottomRight);
        }
        return root;
    }
};