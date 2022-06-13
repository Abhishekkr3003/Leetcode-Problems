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
    
    vector<int> dfs(TreeNode *root){
        if(!root) return {0,INT_MIN,INT_MAX};
        vector<int> left=dfs(root->left);
        vector<int> right=dfs(root->right);
        if(left[0]==INT_MIN || right[0]==INT_MIN) return {INT_MIN,INT_MIN,INT_MIN};
        
        if(left[2]==INT_MAX && right[1]==INT_MIN) {
            res=max(res,root->val);
            return {root->val, root->val, root->val};
        }
        else if(left[2]==INT_MAX && right[1]>root->val) {
            res=max(res, root->val+right[0]);
            return {root->val+right[0], root->val, right[2]};
        }
        else if(right[1]==INT_MIN && left[2]<root->val){
            res=max(res,root->val+left[0]);
            return {root->val+left[0], left[1],root->val};
        }        
        if(left[2]<root->val && right[1]>root->val){
            res=max(res,root->val+left[0]+right[0]);
            return {root->val+left[0]+right[0], left[1], right[2]};
        }
        return {INT_MIN, root->val, root->val};
    }
    
public:
    int maxSumBST(TreeNode* root) {
        dfs(root);
        return res;
    }
};