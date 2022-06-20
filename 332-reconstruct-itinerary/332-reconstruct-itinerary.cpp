class Solution {
    
    bool dfs(unordered_map<string,vector<string>>&graph,unordered_map<string,unordered_set<string>>&vis, string node, int k, vector<string>&path){
        
        
        
        if(path.size()==k) return true;
        
        for(int i=0;i<graph[node].size();i++){
            if(graph[node][i]!=""){
                string nbr=graph[node][i];
                graph[node][i]="";
                path.push_back(nbr);
                vis[node].insert(nbr);
                if(dfs(graph,vis,nbr,k, path)) return true;
                path.pop_back();
                vis[node].erase(nbr);
                graph[node][i]=nbr;
            }
        }
        return false;
    }
    
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,vector<string>>graph;
        unordered_map<string,unordered_set<string>>vis;
        for(auto v:tickets){
            graph[v[0]].push_back(v[1]);
        }
        
        for(auto it=graph.begin();it!=graph.end();it++){
            sort(it->second.begin(),it->second.end());
        }
        vector<string>res;
        res.push_back("JFK");
        dfs(graph,vis,"JFK", tickets.size()+1,res);
        return res;
    }
};