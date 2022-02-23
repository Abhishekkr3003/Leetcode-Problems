/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    Node* dfs(Node *cur, unordered_map<int,Node *>&visited){
        // cout<<cur->val<<endl;
        Node *dup=new Node(cur->val);
        visited[cur->val]=dup;
        for(auto nbr:cur->neighbors){
            if(visited.find(nbr->val)!=visited.end()){
                dup->neighbors.push_back(visited[nbr->val]);
            }else{
                dup->neighbors.push_back(dfs(nbr,visited));
            }
        }
        return dup;
    }
public:
    Node* cloneGraph(Node* node) {
        if(!node) return node;
        unordered_map<int,Node *>visited;
        return dfs(node,visited);
    }
};
