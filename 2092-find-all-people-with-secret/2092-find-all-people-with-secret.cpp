/* 
    Time: O(V+ElogV)
    Space: O(V+E)
    Tag: Dijkstra ( Can be solved with DSU,BFS,DFS)
    Difficulty: H
*/

class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>> &meetings, int firstPerson) {
        vector<pair<int, int>> graph[n];
        for (auto &meet : meetings) {
            graph[meet[0]].push_back({meet[1], meet[2]});
            graph[meet[1]].push_back({meet[0], meet[2]});
        }
        graph[0].push_back({firstPerson, 0});
        graph[firstPerson].push_back({0, 0});
        vector<int> time(n, INT_MAX);
        vector<bool> visited(n, false);
        time[0] = 0;
        set<pair<int, int>> q;
        q.insert({0, 0});
        time[0] = 0;
        while (!q.empty()) {
            int person = q.begin()->second;
            int meetTime = q.begin()->first;
            q.erase(q.begin());
            visited[person] = true;
            for (auto nbr : graph[person]) {
                if (visited[nbr.first] == false && nbr.second >= meetTime && time[nbr.first]>nbr.second) {
                    if (time[nbr.first] != INT_MAX) {
                        q.erase({time[nbr.first], nbr.first});
                    }
                    time[nbr.first] = nbr.second;
                    q.insert({nbr.second, nbr.first});
                }
            }
        }
        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (visited[i]) res.push_back(i);
        }
        return res;
    }
};