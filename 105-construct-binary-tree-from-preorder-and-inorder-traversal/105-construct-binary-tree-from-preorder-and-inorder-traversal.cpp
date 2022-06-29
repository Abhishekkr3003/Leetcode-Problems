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
    
    TreeNode *build(vector<int>&preorder, unordered_map<int,int>&mp, int lo, int hi, int &idx){
        if(idx>=preorder.size()) return NULL;
        if(mp[preorder[idx]]<lo || mp[preorder[idx]]>hi) return NULL;
        TreeNode *node=new TreeNode(preorder[idx]);
        int inordIdx=mp[preorder[idx]];
        idx++;
        node->left=build(preorder,mp,lo,inordIdx-1,idx);
        node->right=build(preorder,mp,inordIdx+1,hi,idx);
        return node;
    }
    
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        int idx=0;
        return build(preorder,mp,0,preorder.size()-1,idx);
    }
};