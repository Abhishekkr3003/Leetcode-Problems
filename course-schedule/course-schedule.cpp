class Solution {
    bool dfs(vector<int>graph[],int node,vector<bool>&visited, vector<bool>&inStack){
        visited[node]=true;
        inStack[node]=true;
        for(int nbr:graph[node]){
            if(!visited[nbr]) {if(dfs(graph,nbr,visited,inStack)) return true;}
            else if(inStack[nbr]) return true;
        }
        inStack[node]=false;
        return false;
        
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        vector<int>graph[numCourses+1];
        for(auto v:pre) graph[v[1]].push_back(v[0]);
        vector<bool>visited(numCourses);
        vector<bool>inStack(numCourses);
        for(int i=0;i<numCourses;i++)
            if(!visited[i] && dfs(graph,i,visited,inStack)) return false;
        return true;       
    }
};