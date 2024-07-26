class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*>q;
        if(!root) return res;
        q.push(root);
        while(!q.empty()) {
            vector<int>v;
            int s = q.size();
            for(int i = 0; i < s; i++){
                TreeNode* temp = q.front(); q.pop();
                v.push_back(temp -> val);
                if(temp -> left)q.push(temp -> left);
                if(temp -> right)q.push(temp -> right);
            }
            res.push_back(v);
        }
        return res;
    }
};