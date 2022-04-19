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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(!root) return {};
        map<int, vector<pair<int,int>>> mp;
        queue<pair<int, TreeNode *>> q;
        q.push({0, root});
        int size=0;
        int row=0;
        while (!q.empty()) {
            int size=q.size();
            row++;
            for(int i=0;i<size;i++){
                TreeNode *node = q.front().second;
                int pos = q.front().first;
                q.pop();
                mp[pos].push_back({row,node->val});
                if (node->left) q.push({pos - 1, node->left});
                if (node->right) q.push({pos + 1, node->right});
            }
        }
        vector<vector<int>>res;
        for (auto p : mp) {
            sort(p.second.begin(), p.second.end(),[](pair<int,int>&p1, pair<int,int>&p2){
                if(p1.first==p2.first) return p1.second<p2.second;
                return p1.first<p2.first;
            });
            res.push_back({});
            for(auto val:p.second) res.back().push_back(val.second);
        }
        return res;
    }
};