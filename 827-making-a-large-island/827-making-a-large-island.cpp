class Solution {
    
    vector<int>parent;
    vector<int>rank;
    
    int find_(int node){
        return parent[node]==-1?node:parent[node]=find_(parent[node]);
    }
    
    void union_(int node1, int node2){
        // cout<<"here\n";
        node1=find_(node1);
        node2=find_(node2);
        
        if(node1!=node2){
            if(rank[node1]<rank[node2]){
                parent[node1]=node2;
                rank[node2]+=rank[node1];
            }else{
                parent[node2]=node1;
                rank[node1]+=rank[node2];
            }
        }
    }
    
    
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        parent.resize(n*n,-1);
        rank.resize(n*n,1);
        
        vector<pair<int,int>>moves={{0,1},{0,-1},{-1,0},{1,0}};
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]){
                    for(auto move:moves){
                        if(i+move.first>=0 && j+move.second>=0 && i+move.first<n && j+move.second<n && grid[i+move.first][j+move.second]){
                            union_(i*n+j,(i+move.first)*n+(j+move.second));
                        }
                    }
                }
            }
        }
        
        // for(int num:parent) cout<<num<<" ";
        // cout<<endl;
        // for(int num:rank) cout<<num<<" ";
        // cout<<endl;
        
        int res=*max_element(rank.begin(),rank.end());
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    int curRes=0;
                    unordered_set<int>st;
                    for(auto move:moves){
                        if(i+move.first>=0 && j+move.second>=0 && i+move.first<n && j+move.second<n && grid[i+move.first][j+move.second]){
                            int comp=find_((i+move.first)*n+(j+move.second));
                            if(st.find(comp)==st.end()) {
                                curRes+=rank[comp];
                                st.insert(comp);
                            }
                        }
                        res=max(res,1+curRes);
                    }
                }
            }
        }
        return res;
    }
};