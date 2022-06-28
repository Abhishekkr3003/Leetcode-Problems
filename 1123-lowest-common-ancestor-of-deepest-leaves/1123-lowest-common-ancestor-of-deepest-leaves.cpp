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
    TreeNode *res;
    int maxDepth=0;
    
    int dfs(TreeNode *root, int depth){
        if(!root) return depth;
        int left=dfs(root->left,depth+1);
        int right=dfs(root->right,depth+1);
        if(left==right && left>=maxDepth){
            res=root;
            maxDepth=left;
        }
        return max(left,right); 
    }
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        dfs(root,0);
        return res;
    }
};