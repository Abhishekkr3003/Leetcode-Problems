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
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return root;
        if(root->val==key){
            if(!root->left && !root->right) return nullptr;
            else if(!root->left) return root->right;
            else if(!root->right) return root->left;
            TreeNode *toReplace=root->right;
            if(!toReplace->left){
                toReplace->left=root->left;
                return toReplace;
            }else{
                TreeNode *parent=root;
                while(toReplace->left) {
                    parent=toReplace;
                    toReplace=toReplace->left;
                }
                if(toReplace->right) parent->left=toReplace->right;
                else parent->left=nullptr;
                toReplace->left=root->left;
                toReplace->right=root->right;
                return toReplace;
            }   
        }
        else if(key<root->val)
            root->left=deleteNode(root->left, key);
        else
            root->right=deleteNode(root->right,key);
        return root;
    }
};