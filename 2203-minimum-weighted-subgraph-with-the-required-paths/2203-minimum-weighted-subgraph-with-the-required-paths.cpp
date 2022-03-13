typedef long long ll;
class Solution {
    vector<ll> dijkstra(int n, vector<pair<int, int>> *graph, int src) {
        vector<ll> distance(n, -1);
        set<pair<ll,ll>>q;
        distance[src] = 0;
        q.insert({0, src});
        while (!q.empty()) {
            ll dist = q.begin()->first;
            int node = q.begin()->second;
            q.erase(q.begin());
            for (auto nbr : graph[node]) {
                if (distance[nbr.first] == -1) {
                    distance[nbr.first] = dist + nbr.second;
                    q.insert({distance[nbr.first], nbr.first});
                } else if (distance[nbr.first] > dist + nbr.second) {
                    q.erase({distance[nbr.first],nbr.first});
                    distance[nbr.first] = dist + nbr.second;
                    q.insert({distance[nbr.first], nbr.first});
                }
            }
        }
        // for(int num:distance) cout<<num<<" ";
        // cout<<endl;
        return distance;
    }
public:
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        vector<pair<int, int>> graph[n];
        vector<pair<int, int>> revGraph[n];
        for (auto edge : edges) {
            graph[edge[0]].push_back({edge[1], edge[2]});
            revGraph[edge[1]].push_back({edge[0], edge[2]});
        }
        auto src1ToAll = dijkstra(n, graph, src1);
        auto src2ToAll = dijkstra(n, graph, src2);
        auto destToAll = dijkstra(n, revGraph, dest);
        if (destToAll[src1] == -1 || destToAll[src2] == -1) return -1;
        // cout<<"here";
        ll dist1 = LLONG_MAX;
        for (int i = 0; i< n; i++) {
            if(destToAll[i]!=-1 && src1ToAll[i]!=-1 && src2ToAll[i]!=-1)
                dist1 = min(dist1, destToAll[i] + src1ToAll[i] + src2ToAll[i]);
        }
        ll dist2 = destToAll[src1] + destToAll[src2];
        ll dist3 = LLONG_MAX, dist4 = LLONG_MAX;
        if (src1ToAll[src2] != -1) dist3 = src1ToAll[src2] + src2ToAll[dest];
        if (src2ToAll[src1] != -1) dist4 = src2ToAll[src1] + src1ToAll[dest];
        // cout<<dist1<<" "<<dist2<<" "<<dist3<<" "<<dist4<<endl;
        return min(dist1, min(dist2, min(dist3, dist4)));
    }
};