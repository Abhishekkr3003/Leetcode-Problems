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
    int res=0;
    
    void findMax(TreeNode* root, int maxSoFar){
        if(!root) return;
        if(root->val>=maxSoFar) res++;
        findMax(root->left, max(maxSoFar,root->val));
        findMax(root->right, max(maxSoFar,root->val));
    }
    
public:
    int goodNodes(TreeNode* root) {
        findMax(root,INT_MIN);
        return res;
    }
};