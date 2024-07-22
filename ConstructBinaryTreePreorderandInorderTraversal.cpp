class Solution {
public:
int findPos(int x, vector<int>& inorder){
    int index =-1;
    for(int i=0;i<inorder.size();i++){
        if(inorder[i]==x) return i;
    }
    return index;
}
    TreeNode* createTree(int start , int end , int& index , vector<int>& preorder, vector<int>& inorder){
        if(start > end ) return NULL;
        if(index >= preorder.size()) return NULL;
        TreeNode* root = new TreeNode(preorder[index]);
        int find = findPos(preorder[index],inorder);
        index++;
        root->left  = createTree(start,find-1,index,preorder,inorder);
        root->right = createTree(find+1,end,index,preorder,inorder);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int start = 0;
        int end   = preorder.size()-1;
        int index = 0;
        return createTree(start, end, index, preorder, inorder);
    }
};