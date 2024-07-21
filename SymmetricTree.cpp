class Solution {
public:
    bool check(TreeNode* p, TreeNode* q) {
        if(p == nullptr && q == nullptr) return true;
        if((p == nullptr && q != nullptr) || (p != nullptr && q == nullptr)) 
        return false;
        if(p -> val != q -> val) return false;
        bool l_side = check(p -> left, q -> right);
        bool r_side = check(p -> right, q -> left);
        if(l_side == false || r_side == false) return false;
        return true;
    }
    bool isSymmetric(TreeNode* root) {
        return check(root -> left, root -> right);
    }
};