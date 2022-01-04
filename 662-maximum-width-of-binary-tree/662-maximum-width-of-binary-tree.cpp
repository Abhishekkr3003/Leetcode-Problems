// Main issue is overflow problem

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
    int widthOfBinaryTree(TreeNode* root) {
        deque<pair<TreeNode*,int>>q;
        int res=0;
        q.push_back({root,0});
        while(!q.empty()){
            int size=q.size();
            res=max(res,q.back().second-q.front().second+1);
            int min_=q.front().second;
            for(int i=0;i<size;i++){
                TreeNode *cur=q.front().first;
                int val=q.front().second;
                q.pop_front();
                if(cur->left) q.push_back({cur->left, val*2-min_});
                if(cur->right) q.push_back({cur->right, val*2+1-min_});
            }
        }
        return res;
    }
};