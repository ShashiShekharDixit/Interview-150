class Solution {
public:
    int maxPathTotal(TreeNode* root, int &maxSum){
        if(root == NULL) {
            return 0;
        }
        int leftSubTreeSum = max(0, maxPathTotal(root -> left, maxSum));
        int rightSubTreeSum = max(0, maxPathTotal(root -> right, maxSum));
        int totalSumAtNode = leftSubTreeSum + rightSubTreeSum + root -> val;
        maxSum = max(maxSum, totalSumAtNode);
        int maxPossiblePath = root -> val + max(leftSubTreeSum, rightSubTreeSum);
        return maxPossiblePath;
    }
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        maxPathTotal(root, maxSum);
        return maxSum;
    }
};