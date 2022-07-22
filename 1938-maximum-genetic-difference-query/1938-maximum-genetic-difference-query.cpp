struct Node{
    int count;
    vector<Node*>children;
    Node(){
        children.resize(2,NULL);
        count=0;
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
        for(int i=18;i>=0;i--){
            bool bit=(num&(1<<i));
            if(!cur->children[bit]) cur->children[bit]=new Node();
            cur=cur->children[bit];           
            cur->count++;
        }
    }
    
    void remove(int num) {
        Node *cur=root;
        for(int i=18;i>=0;i--){
            bool bit=(num&(1<<i));
            cur=cur->children[bit];           
            cur->count--;
        }
    }
    
    int search(int num) {
        int res=0;
        Node *cur=root;
        for(int i=18;i>=0;i--){
            bool bit=(num&(1<<i));
            if(cur->children[!bit] && cur->children[!bit]->count>0) {
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
    
    unordered_map<int,unordered_map<int,int>>mp;
    Trie *t;
    
    void dfs(vector<int>gr[],int cur){
        t->insert(cur);
        for(auto &child:mp[cur]){
            mp[cur][child.first]=t->search(child.first);
        }
        for(int &child:gr[cur]){
            dfs(gr,child);
        }
        t->remove(cur);
    }
    
public:
    vector<int> maxGeneticDifference(vector<int>& parents, vector<vector<int>>& queries) {
        t=new Trie();

        int n=parents.size();
        vector<int>gr[n];
        
        int root=-1;
        
        for(int i=0;i<n;i++){
            if(parents[i]==-1) root=i;
            else gr[parents[i]].push_back(i);
        }
        
        for(auto &v:queries){
            mp[v[0]][v[1]]=-1;
        }
        
        dfs(gr,root);
        
        vector<int>res(queries.size());
        for(int i=0;i<queries.size();i++){
            res[i]=mp[queries[i][0]][queries[i][1]];
        }
        
        return res;
    }
};