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
    vector<string>res;
    
    void dfs(TreeNode *root, string &path){
        if(!root) return;
        if(!root->left && !root->right) {
            string temp=to_string(root->val);
            path+=temp;
            res.push_back(path);
            for(int i=0;i<temp.length();i++) path.pop_back();
            return;
        } 
        string temp=to_string(root->val)+"->";
        path+=temp;
        dfs(root->left,path);
        dfs(root->right, path);
        for(int i=0;i<temp.length();i++) path.pop_back();
    }
    
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        string path="";
        dfs(root,path);
        return res;
    }
};