class Solution {
    
    bool dfs(vector<int>graph[], vector<int>&vis, int cur, vector<int>&res){
        vis[cur]=1;
        for(int nbr:graph[cur]){
            if(vis[nbr]==1) return false;
            else if(vis[nbr]==0){
                if(!dfs(graph,vis,nbr,res)) return false;
            }
        }
        vis[cur]=2;
        res.push_back(cur);
        return true;
    }
    
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
        vector<int>vis(numCourses,0);
        vector<int>graph[numCourses];
        for(auto &edge:pre){
            graph[edge[1]].push_back(edge[0]);
        }
        vector<int>res;
        for(int i=0;i<numCourses;i++){
            if(vis[i]==0){
                if(!dfs(graph,vis,i,res)) return {};
            }
        }
        reverse(res.begin(),res.end());
        return res;
    }
};