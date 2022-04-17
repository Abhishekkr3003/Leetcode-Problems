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
    TreeNode *head, *ptr;
    void solve(TreeNode* root){
        if(!root) return;
        solve(root->left);
        if(!head) {
            head=root;
            ptr=root;
        }
        else{
            ptr->left=root;
            ptr=root;
        }
        solve(root->right);
    }
    void changeToRight(TreeNode *root){
        if(!root) return;
        root->right=root->left;
        root->left=NULL;
        changeToRight(root->right);
    }
public:
    TreeNode* increasingBST(TreeNode* root) {
        solve(root);
        ptr->right=NULL;
        ptr->left=NULL;
        changeToRight(head);
        return head;
    }
};