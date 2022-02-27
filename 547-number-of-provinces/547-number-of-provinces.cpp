class Solution {
    vector<int>parent;
    vector<int>rank;
    
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
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        parent.resize(n,-1);
        rank.resize(n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]) u(i,j);
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            if(parent[i]==-1) count++;
        }
        return count;
    }
};