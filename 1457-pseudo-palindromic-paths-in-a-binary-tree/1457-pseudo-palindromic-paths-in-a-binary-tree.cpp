// Bit Manipulation can be used instead of map by using 10 bits than 10 mappings, see solution section for more details.

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
    int freq[10]={0};
    
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        freq[root->val]++;
        int res=0;
        if(!root->left && !root->right){
            int oddCount=0;
            for(int i=1;i<=9;i++){
                if(freq[i]&1) oddCount++;
            }
            if(oddCount<=1) res++;
        }
        if(root->left) res+=pseudoPalindromicPaths(root->left);
        if(root->right) res+=pseudoPalindromicPaths(root->right);
        
        freq[root->val]--;
        return res;
    }
};