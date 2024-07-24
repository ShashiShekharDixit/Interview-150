class BSTIterator {
public:
vector<TreeNode*>Nodes;
int start = 0;
void inorder(TreeNode* root, vector<TreeNode*>& Nodes) {
    if(root == NULL) return;
    inorder(root -> left, Nodes);
    Nodes.push_back(root);
    inorder(root -> right, Nodes);
}
    BSTIterator(TreeNode* root) {
        inorder(root, Nodes);
    }
    
    int next() {
        int x = Nodes[start]-> val;
        start++;
        return x;
    }
    
    bool hasNext() {
        if(start < Nodes.size()) return true;
        return false;
    }
};