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
    int res;
    void inorder(TreeNode *root, int k, int &count){
        if(!root) return;
        if(res==-1) inorder(root->left,k,count);
        count++;
        if(k==count) res=root->val;
        if(res==-1) inorder(root->right,k,count);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        res=-1;
        int count=0;
        inorder(root,k,count);
        return res;
    }
};