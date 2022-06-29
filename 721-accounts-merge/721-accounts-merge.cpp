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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string,int>mapToIdx;
        int n=accounts.size();
        parent.resize(n,-1);
        rank.resize(n,1);
        
        for(int i=0;i<n;i++){
            int m=accounts[i].size();
            for(int j=1;j<m;j++){
                if(mapToIdx.find(accounts[i][j])==mapToIdx.end()){
                    mapToIdx[accounts[i][j]]=i;
                }else{
                    u(i,mapToIdx[accounts[i][j]]);
                }
            }
        }
        
        // for(int i=0;i<n;i++) cout<<parent[i]<<endl;
        
        unordered_map<int,int>fIdx;
        vector<set<string>>res;
        vector<vector<string>>ans;
        
        for(int i=0;i<n;i++){
            if(parent[i]==-1){
                fIdx[i]=res.size();
                res.push_back({});
                ans.push_back({accounts[i][0]});
            }
        }
        
        for(int i=0;i<n;i++){
            int par=f(i);
            for(int j=1;j<accounts[i].size();j++){
                res[fIdx[par]].insert(accounts[i][j]);
            }
        }
        for(int i=0;i<res.size();i++){
            for(string val:res[i]){
                ans[i].push_back(val);
            }
        }
        
        return ans;
        
    }
};