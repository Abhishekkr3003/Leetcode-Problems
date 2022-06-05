/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    vector<int>res;
    
    void findAtDist(TreeNode *root, int dist){
        if(!root) return;
        if(dist==0){
            res.push_back(root->val);
            return;
        }
        findAtDist(root->left,dist-1);
        findAtDist(root->right,dist-1);
    }
    
    int dfs(TreeNode* root, TreeNode* target, int k){
        if(!root) return -1;
        if(root==target){
            if(k==0){
                res.push_back(root->val);
                return -1;
            }
            findAtDist(root->left, k-1);
            findAtDist(root->right, k-1);
            return k-1;
        }
        int left=dfs(root->left,target,k);
        if(left!=-1){
            if(left==0){
                res.push_back(root->val);
                return -1;
            }
            findAtDist(root->right, left-1);
            return left-1;
        }
        int right=dfs(root->right,target,k);
        if(right!=-1){
            if(right==0){
                res.push_back(root->val);
                return -1;
            }
            findAtDist(root->left, right-1);
            return right-1;
        }
        return -1;
    }
    
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(!root) return {};
        dfs(root,target,k);
        return res;
    }
};