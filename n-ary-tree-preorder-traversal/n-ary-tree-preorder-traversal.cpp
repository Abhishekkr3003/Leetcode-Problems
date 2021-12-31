/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    void traversal(Node *root, vector<int>&res){
        res.push_back(root->val);
        for(Node *child:root->children){
            traversal(child,res);
        }
    }
public:
    vector<int> preorder(Node* root) {
        if(!root) return {};
        vector<int>res;
        traversal(root,res);
        return res;
    }
};