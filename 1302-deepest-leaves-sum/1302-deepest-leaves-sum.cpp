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
    int maxDepth=0;
    int maxDepthSum=0;
    
    void findSum(TreeNode *root, int depth){
        if(!root) return;
        if(depth>maxDepth){
            maxDepth=depth;
            maxDepthSum=root->val;
        }else if(depth==maxDepth) maxDepthSum+=root->val;
        findSum(root->left,depth+1);
        findSum(root->right,depth+1);
    }
public:
    int deepestLeavesSum(TreeNode* root) {
        findSum(root,0);
        return maxDepthSum;
    }
};