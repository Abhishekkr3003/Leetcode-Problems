typedef long long ll;

class Solution {
    
    void dfs(vector<ll>graph[], vector<ll>&low, vector<ll>&disc, ll &time, vector<vector<int>>&res, int parent, int cur){
        // cout<<time<<endl;
        time++;
        disc[cur]=time;
        low[cur]=time;
        
        for(int nbr:graph[cur]){
            if(nbr!=parent){
                if(disc[nbr]==LLONG_MAX){
                    dfs(graph,low,disc,time,res,cur,nbr);
                    low[cur]=min(low[cur],low[nbr]);
                    if(low[nbr]>disc[cur])
                        res.push_back({cur,nbr});
                }else{
                    low[cur]=min(low[cur],disc[nbr]);
                }
            }
        }
    }
    
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<ll>graph[n];
        
        for(int i=0;i<connections.size();i++){
            graph[connections[i][0]].push_back(connections[i][1]);
            graph[connections[i][1]].push_back(connections[i][0]);
        }
        
        vector<ll>disc(n, LLONG_MAX);
        vector<ll>low(n, LLONG_MAX);
        
        ll time=0;
        
        vector<vector<int>>res;
        
        dfs(graph,low,disc,time,res, -1, 0);
        return res;
    }
};