class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL){
            return res;
        }
        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true;
        while(!q.empty()){
            int size = q.size();
            vector<int> temp(size);
            for(int i = 0; i < size; i++) {
                TreeNode* frontNode = q.front();
                q.pop();
                int index = leftToRight ? i : size - i - 1;
                temp[index] = frontNode -> val;
                if(frontNode -> left) {
                    q.push(frontNode -> left);
                }
                if(frontNode -> right) {
                    q.push(frontNode -> right);
                }
            }
            leftToRight = !leftToRight;
            res.push_back(temp);
        }
        return res;
    }
};