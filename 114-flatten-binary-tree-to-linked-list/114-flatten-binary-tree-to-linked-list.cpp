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
    
    TreeNode *dfs(TreeNode *root){
        if(!root->left && !root->right) return root;
        if(root->left) swap(root->left,root->right);
        TreeNode *lastPoint=dfs(root->right);
        if(root->left){
            lastPoint->right=root->left;
            root->left=NULL;
            lastPoint=dfs(lastPoint->right);
        }
        return lastPoint;
    }
    
public:
    void flatten(TreeNode* root) {
        if(!root) return;
        dfs(root);
    }
};