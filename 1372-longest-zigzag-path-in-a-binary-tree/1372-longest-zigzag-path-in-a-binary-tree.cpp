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
    
    void solve(TreeNode *root,int curLen, int dir){
        if(!root) return;
        // cout<<root->val<<" "<<curLen<<endl;
        res=max(res,curLen);
        if(dir==0){
            solve(root->right,curLen+1,1);
            solve(root->left,1,0);
        }
        if(dir==1){
            solve(root->left,curLen+1,0);
            solve(root->right,1,1);
        }
    }
    
public:
    int longestZigZag(TreeNode* root) {
        solve(root->left,1,0);
        solve(root->right,1,1);
        return res;
    }
};