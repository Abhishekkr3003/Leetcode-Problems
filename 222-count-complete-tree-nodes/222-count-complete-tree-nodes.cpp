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
    int findHeight(TreeNode *root){
        return ((!root)?0:1+findHeight(root->left));
    }
    
public:
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int leftHeight=findHeight(root->left);
        int rightHeight=findHeight(root->right);
        
        if(leftHeight==rightHeight){
            return (1<<(leftHeight))+countNodes(root->right);
        }
        return (1<<(rightHeight))+countNodes(root->left);
    }
};