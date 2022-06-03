class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
        vector<int>indeg(numCourses,0);
        vector<int>graph[numCourses];
        for(auto &edge:pre){
            graph[edge[1]].push_back(edge[0]);
            indeg[edge[0]]++;
        }
        queue<int>q;
        vector<int>res;
        for(int i=0;i<numCourses;i++){
            if(indeg[i]==0) q.push(i);
        }
        while(!q.empty()){
            int cur=q.front();
            q.pop();
            res.push_back(cur);
            for(int nbr:graph[cur]){
                indeg[nbr]--;
                if(indeg[nbr]==0) q.push(nbr);
            }
        }
        if(res.size()==numCourses) return res;
        return {};
    }
};