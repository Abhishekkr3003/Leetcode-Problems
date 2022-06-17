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
    int cameras=0;
    
    int solve(TreeNode *root){
        if(!root->left && !root->right) return 0;
        
        if(root->left && root->right){
            int left=solve(root->left);
            int right=solve(root->right);

            if(!left || !right){
                cameras++;
                return 2;
            }
            return max(left,right)-1;
        }
        
        if(root->left){
            int left=solve(root->left);
            if(left==0){
                cameras++;
                return 2;
            }
            return left-1;
        }
        int right=solve(root->right);
        if(right==0){
            cameras++;
            return 2;
        }
        return right-1;
    }
    
public:
    int minCameraCover(TreeNode* root) {
        if(!root->left && !root->right) return 1;
        if(solve(root)==0) return cameras+1;
        return cameras;
    }
};