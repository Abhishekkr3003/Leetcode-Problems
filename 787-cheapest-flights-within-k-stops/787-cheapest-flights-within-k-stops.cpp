class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int>dist(n,INT_MAX), temp(n,INT_MAX);
        dist[src]=0;
        temp[src]=0;
        for(int i=0;i<=k;i++){
            for(auto &edge:flights){
                int s=edge[0];
                int d=edge[1];
                int w=edge[2];
                if(dist[s]!=INT_MAX && temp[d]>dist[s]+w)
                    temp[edge[1]]=dist[edge[0]]+edge[2];
            }
            dist=temp;
        }
        return dist[dst]==INT_MAX?-1:temp[dst];
    }
};