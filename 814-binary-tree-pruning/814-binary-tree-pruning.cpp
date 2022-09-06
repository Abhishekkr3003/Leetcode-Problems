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
    
    bool solve(TreeNode *root){
        if(!root) return false;
        
        bool left=solve(root->left);
        bool right=solve(root->right);
        
        if(!left) root->left=NULL;
        if(!right) root->right=NULL;
        
        return left||right||root->val;
    }
    
public:
    TreeNode* pruneTree(TreeNode* root) {
        bool res=solve(root);
        if(!res) return NULL;
        return root;
    }
};