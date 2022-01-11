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

    void dfs(TreeNode *root, int curVal, int &sum){
        curVal=(curVal<<1)+root->val;
        if(!root->left && !root->right) sum+=curVal;
        else if(!root->right) dfs(root->left,curVal,sum);
        else if(!root->left) dfs(root->right,curVal,sum);
        else {
            dfs(root->left,curVal,sum);
            dfs(root->right,curVal,sum);            
        }
    }
    
public:
    int sumRootToLeaf(TreeNode* root) {
        int res=0;
        dfs(root,0,res);
        return res;
    }
};