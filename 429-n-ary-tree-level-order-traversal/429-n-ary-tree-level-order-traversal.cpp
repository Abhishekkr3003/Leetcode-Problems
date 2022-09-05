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
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(!root) return {};
        vector<vector<int>>res;
        queue<Node*>q;
        
        q.push(root);
        res.push_back({root->val});
        
        int size;
        
        while(!q.empty()){
            size=q.size();
            res.push_back({});
            
            for(int i=0;i<size;i++){
                Node *cur=q.front();
                q.pop();
                for(Node *nbr:cur->children){
                    res.back().push_back(nbr->val);
                    q.push(nbr);
                }
            }   
        }
        res.pop_back();
        return res;
    }
};