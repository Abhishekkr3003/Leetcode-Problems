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
    vector<TreeNode*> allPossibleFBT(int n) {
        vector<vector<TreeNode *>>t(n+1);
        if(n%2==0) return {};
        if(n==1) return {new TreeNode(0)};
        t[1].push_back(new TreeNode(0));
        
        for(int i=3;i<=n;i++){
            for(int j=1;j<=i-1;j++){
                for(TreeNode *left:t[j]){
                    for(TreeNode *right:t[i-1-j]){
                        TreeNode *curNode=new TreeNode(0,left,right);
                        t[i].push_back(curNode);
                    }
                }
            }
        }
        return t[n];
    }
};