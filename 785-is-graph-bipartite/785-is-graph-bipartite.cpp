class Solution {
    bool dfs(int cur, vector<vector<int>> graph, vector<int>&visited)
    {
        for(auto nbr:graph[cur])
        {
            if(!visited[nbr])
            {
                visited[nbr]=3-visited[cur];
                if(!dfs(nbr, graph, visited))
                   return false;
            }
            else if((visited[nbr]==visited[cur]))
                return false;
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int>visited(graph.size(),0);
        for(int i=0;i<graph.size();i++)
        {
            if(!visited[i])
            {
                visited[i]=1;
                if(!dfs(i, graph, visited))
                    return false;
            }
        }
        return true;
    }
};