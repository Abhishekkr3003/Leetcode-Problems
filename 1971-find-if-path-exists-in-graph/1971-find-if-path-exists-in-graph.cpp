class Solution {
    vector<int>parent, rank;
    
    int f(int a){
        return parent[a]==-1?a:parent[a]=f(parent[a]);
    }
    
    void u(int a, int b){
        a=f(a);
        b=f(b);
        
        if(a!=b){
            if(rank[a]<rank[b]){
                parent[a]=b;
                rank[b]+=rank[a];
            }else{
                parent[b]=a;
                rank[a]+=rank[b];
            }
        }
    }
    
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        parent.resize(n,-1);
        rank.resize(n,1);
        
        for(auto edge:edges) u(edge[0],edge[1]);
        
        return f(source)==f(destination);
    }
};