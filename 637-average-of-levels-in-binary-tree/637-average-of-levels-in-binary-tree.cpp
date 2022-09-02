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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double>ans;
        queue<pair<TreeNode*,int>>q;
        q.push({root, 0});
        double sum=0;
        int count=0;
        int ht=0;
        while(!q.empty())
        {
            pair p=q.front();
            q.pop();
            //cout<<p.first->val<<"\n";
            if(p.second>ht)
            {
                ans.push_back(sum/count);
                sum=count=0;
                ht=p.second;
            }
            sum+=p.first->val;
            count++;
            
            if(p.first->left)
                q.push({p.first->left, p.second+1});
            if(p.first->right)
                q.push({p.first->right, p.second+1});
            
        }
        ans.push_back(sum/count);
        return ans;
    }
};