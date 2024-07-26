class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        if(!root)
        return {};
        vector<double> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int n = q.size();
            double sum = 0;
            for(int i = 0; i < n; ++i){
                TreeNode* node = q.front();
                q.pop();
                sum += node -> val;
                if(node -> left)
                q.push(node -> left);
                if(node -> right)
                q.push(node -> right);
            }
            ans.push_back(sum / n);
        }
        return ans;
    }
};