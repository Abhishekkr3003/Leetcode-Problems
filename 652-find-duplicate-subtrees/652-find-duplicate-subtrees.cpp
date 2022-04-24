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
/* 
    Time: O(n)
    Space: O(n*h) || We are storing each node value its depth times in hashmap
    Tag: Serialize and Deserialize Binary Tree
    Difficulty: MH
*/

class Solution {
    unordered_map<string, pair<int, TreeNode *>> mp;

    string preorder(TreeNode *root) {
        if (!root) return "";
        string res = to_string(root->val) + "|" + preorder(root->left) + "|" + preorder(root->right);
        if (mp.find(res) == mp.end())
            mp[res] = {1, root};
        else
            mp[res].first++;
        return res;
    }

public:
    vector<TreeNode *> findDuplicateSubtrees(TreeNode *root) {
        preorder(root);
        vector<TreeNode *> res;
        for (auto p : mp) {
            if (p.second.first > 1) res.push_back(p.second.second);
        }
        return res;
    }
};