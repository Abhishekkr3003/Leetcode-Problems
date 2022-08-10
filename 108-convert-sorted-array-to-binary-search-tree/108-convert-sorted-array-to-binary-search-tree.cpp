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
    TreeNode *makeTree(int i, int j, vector<int>&nums){
        if(i>j) return nullptr;
        if(i==j) return new TreeNode(nums[i]);
        int mid=i+(j-i)/2;
        TreeNode *newNode=new TreeNode(nums[mid]);
        newNode->left=makeTree(i, mid-1, nums);
        newNode->right=makeTree(mid+1,j,nums);
        return newNode;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return makeTree(0,nums.size()-1,nums);
    }
};