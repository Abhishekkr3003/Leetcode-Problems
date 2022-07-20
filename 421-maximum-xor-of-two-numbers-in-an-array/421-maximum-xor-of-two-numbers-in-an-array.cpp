struct Node{
    vector<Node*>children;
    Node(){
        children.resize(2,NULL);
    }
};

class Trie {
    Node *root;
public:
    Trie() {
        root=new Node();
    }
    
    void insert(int num) {
        Node *cur=root;
        for(int i=31;i>=0;i--){
            bool bit=(num&(1<<i));
            if(!cur->children[bit]) cur->children[bit]=new Node();
            cur=cur->children[bit];           
        }
    }
    
    int search(int num) {
        int res=0;
        Node *cur=root;
        for(int i=31;i>=0;i--){
            bool bit=(num&(1<<i));
            if(cur->children[!bit]) {
                res+=(1<<i);
                cur=cur->children[!bit];
            }else{
                cur=cur->children[bit];
            }
        }
        return res;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie *t=new Trie();
        int res=0;
        for(int &num:nums){
            t->insert(num);
            res=max(res,t->search(num));
        }
        return res;
    }
};