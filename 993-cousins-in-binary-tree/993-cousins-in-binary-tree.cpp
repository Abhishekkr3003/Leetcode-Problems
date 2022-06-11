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
    int level1=-1;
    int level2=-1;
    
    void dfs(TreeNode *root, int x, int y, int depth){
        if(!root) return;
        if(root->val==x) level1=depth;
        if(root->val==y) level2=depth;
        
        if(root->left && root->right){
            if((root->left->val==x || root->right->val==x) && (root->left->val==y || root->right->val==y) ) return;
        }
        dfs(root->left,x,y,depth+1);
        dfs(root->right,x,y,depth+1);        
    }
    
public:
    bool isCousins(TreeNode* root, int x, int y) {
        dfs(root,x,y,1);
        if(level1!=-1 && level1==level2) return true;
        return false;
    }
};