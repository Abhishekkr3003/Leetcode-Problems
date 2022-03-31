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
    map<int,vector<pair<int,int>>>mp;
    
    void solve(TreeNode *root, int vert, int horiz){
        if(!root) return;
        mp[horiz].push_back({root->val,vert});
        solve(root->left, vert+1, horiz-1);
        solve(root->right, vert+1, horiz+1);
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        solve(root,0,0);
        vector<vector<int>>res(mp.size());
        int j=0;
        // for(auto p:mp){
        //     for(auto val:p.second) cout<<val.first<<" ";
        //     cout<<endl;
        // }
        for(auto p:mp){
            sort(p.second.begin(), p.second.end(),[](auto &a, auto &b){
                if(a.second!=b.second) return a.second<b.second; 
                return a.first<b.first;
            });
            for(int i=0;i<p.second.size();i++){
                res[j].push_back(p.second[i].first);
            }
            j++;
        }
        return res;
    }
};