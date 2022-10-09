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
    bool find(int val, TreeNode *root){
        if(!root) return false;
        while(root){
            if(root->val==val) return true;
            if(root->val<val) root=root->right;
            else root=root->left;
        }
        return false;
    }
    
    bool solve(TreeNode *root, int k, TreeNode *globRoot){
        if(!root) return false;
        if(k-root->val!=root->val && find(k-root->val,globRoot)) return true;
        return solve(root->left,k,globRoot) || solve(root->right,k,globRoot);
    }
    
public:
    bool findTarget(TreeNode* root, int k) {
        return solve(root,k,root);
    }
};