class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) {
            return true;
        }
        if(!p || !q || p -> val != q -> val) {
            return false;
        } else {
            bool lsol = isSameTree(p -> left, q -> left);
            if(lsol) {
                return isSameTree(p -> right, q -> right);
            } else {
                return false;
            }
        }
    }
};