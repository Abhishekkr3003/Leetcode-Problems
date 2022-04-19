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
    TreeNode *prev, *node1, *node2;
    void solve(TreeNode *root){
        if(!root) return;
        solve(root->left);
        if(!node1){
            if(prev && prev->val>root->val) {
                node1=prev;
            }  
        }
        if(node1){
            if(!node2) node2=root;
            else if(node2->val>root->val) node2=root;
        }
        prev=root;
        solve(root->right);
    }
public:
    void recoverTree(TreeNode* root) {
        prev=NULL, node1=NULL, node2=NULL;
        solve(root);
        swap(node1->val, node2->val);
    }
};