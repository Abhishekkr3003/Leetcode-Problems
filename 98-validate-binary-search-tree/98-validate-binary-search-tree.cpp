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
    bool traversal(TreeNode* root, int max, int min){
        //cout<<root->val<<" "<<max<<" "<<min<<"\n";
        if(root->val>max || root->val<min){
            //cout<<"Here";
            return false;
        }
        if((root->left && root->left->val>=root->val) || (root->right && root->right->val<=root->val)){
            return false;
        }
        //cout<<root->val<<" "<<max<<" "<<min<<"\n";
        bool l=true, r=true;
        if(root->left){
            l=traversal(root->left, (root->val)-1, min);
            if(!l) return false;
        }
        if(root->right){
            r=traversal(root->right, max, (root->val)+1);
            if(!r) return false;
        }
        return true;
        
    }
public:
    bool isValidBST(TreeNode* root) {
        return traversal(root, INT_MAX, INT_MIN);        
    }
};