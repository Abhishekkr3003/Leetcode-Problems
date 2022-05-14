/* 
    Time: O()
    Space: O()
    Tag: 
    Difficulty: 
*/

class Solution {
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k) {
        vector<pair<int, int>> graph[n + 1];
        for (vector<int> &edge : times) {
            graph[edge[0]].push_back({edge[1], edge[2]});
        }
        vector<int> distances(n + 1, INT_MAX);
        distances[k] = 0;
        set<pair<int,int>> q;
        q.insert({0, k});
        vector<bool> visited(n + 1, false);
        visited[k]=true;
        while (!q.empty()) {
            int node = q.begin()->second;
            int dist = q.begin()->first;
            q.erase(q.begin());
            visited[node] = true;
            for (auto &nbr : graph[node]) {
                if (!visited[nbr.first]) {
                    if (distances[nbr.first] > dist + nbr.second) {
                        if(distances[nbr.first]!=INT_MAX){
                            q.erase({distances[nbr.first], nbr.first});
                        }
                        distances[nbr.first] = dist + nbr.second;
                    }
                    q.insert({distances[nbr.first], nbr.first});
                }
            }
        }
        int maxEle = *max_element(distances.begin() + 1, distances.end());
        return (maxEle == INT_MAX ? -1 : maxEle);
    }
};