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
    
    void getRightView(TreeNode *root, vector<int>&res, int &maxDepth, int curDepth){
        if(!root) return;
        
        if(curDepth>maxDepth){
            res.push_back(root->val);
            maxDepth++;
        }
        getRightView(root->right,res,maxDepth, curDepth+1);
        getRightView(root->left,res,maxDepth, curDepth+1);        
    }
    
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int>res;
        int maxDepth=0;
        getRightView(root,res,maxDepth, 1);
        return res;
    }
};