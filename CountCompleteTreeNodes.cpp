class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int count = 0;
        while(!q.empty()) {
            TreeNode* current = q.front();
            q.pop();
            count++;
            if(current -> left != NULL){
                q.push(current -> left);
            }
            if(current -> right != NULL){
                q.push(current -> right);
            }
        }
        return count;
    }
};