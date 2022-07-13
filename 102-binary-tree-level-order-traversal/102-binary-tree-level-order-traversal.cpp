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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root)
            return {};
        int levelSize=1;
        vector<vector<int>>res;
        vector<int>level;
        queue<TreeNode*>q;
        q.push(root);
        TreeNode* temp;
        while(!q.empty()){
            temp=q.front(); q.pop();
            level.push_back(temp->val);
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
            levelSize--;
            if(levelSize==0){
                res.push_back(level);
                level.clear();
                levelSize=q.size();
            }
        }
        return res;
    }
};