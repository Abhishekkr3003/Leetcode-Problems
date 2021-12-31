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
    int findMaxDiff(TreeNode *root, int min_, int max_){
        if(!root) return 0;
        int left=findMaxDiff(root->left, min(min_,root->val), max(max_, root->val));
        int right=findMaxDiff(root->right, min(min_,root->val), max(max_, root->val));
        int curDiff=max(abs(root->val-min_),abs(root->val-max_));
        return max(left,max(right,curDiff));
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        return findMaxDiff(root, root->val,root->val);
    }
};