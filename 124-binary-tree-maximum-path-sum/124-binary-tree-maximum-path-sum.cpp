/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int maxSum=INT_MIN;
    
    int pathSum(TreeNode *root){
        if(!root) return 0;
        int left=pathSum(root->left);
        int right=pathSum(root->right);
        
        maxSum=max({maxSum, root->val+left, root->val+right, root->val+left+right, root->val});
        return max({0,root->val, root->val+left, root->val+right});
    }
    
public:
    int maxPathSum(TreeNode* root) {
        pathSum(root);
        return maxSum;
    }
};