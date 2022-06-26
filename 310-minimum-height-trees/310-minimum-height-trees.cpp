class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1) return {0};
        vector<int>indeg(n);
        vector<int>graph[n];
        for(auto edge:edges){
            indeg[edge[0]]++;
            indeg[edge[1]]++;
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        queue<int>q;
        
        for(int i=0;i<n;i++){
            if(indeg[i]==1) {
                q.push(i);
                indeg[i]=0;
            }
        }
        
        vector<int>temp;
        while(!q.empty()){
            int size=q.size();
            temp.clear();
            for(int i=0;i<size;i++){
                int cur=q.front();
                q.pop();
                temp.push_back(cur);
                for(int nbr:graph[cur]){
                    indeg[nbr]--;
                    if(indeg[nbr]==1) q.push(nbr);
                }
            }
        }
        return temp;
    }
};