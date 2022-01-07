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

// Better alt is BFS
class Solution {
    int maxLevel;
    int res;
    int val;
    
    void dfs(TreeNode *root, int level, int curVal){
        if(!root) return;
        if(level>maxLevel){
            maxLevel=level;
            res=curVal;
            val=root->val;
        }else if(level==maxLevel && res>curVal) {
            res=curVal;
            val=root->val;
        }
        dfs(root->left,level+1,curVal-1);
        dfs(root->right,level+1,curVal+1);
    }
    
public:
    int findBottomLeftValue(TreeNode* root) {
        res=INT_MAX;
        maxLevel=0;
        val=root->val;
        dfs(root,0,0);
        return val;
    }
};