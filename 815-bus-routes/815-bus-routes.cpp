/*
    Time: O((N^2*Routes[i].size())+ N^2) 
    Space: O(N^2)
    Tag: BFS, Hashing, Hashset
    Difficulty: H
*/

class Solution {
public:
    int numBusesToDestination(vector<vector<int>> &routes, int source, int target) {
        if (target == source) return 0;
        vector<unordered_set<int>> routesquickSearch;
        for (auto vec : routes)
            routesquickSearch.push_back(unordered_set<int>(vec.begin(), vec.end()));

        unordered_set<int> dest;
        int n = routes.size();
        queue<int> q;
        vector<int> graph[n];
        vector<bool> visited(n, 0);
        for (int i = 0; i < n; i++) {
            if (routesquickSearch[i].find(source) != routesquickSearch[i].end()) {
                q.push(i);
                visited[i] = true;
            }
            if (routesquickSearch[i].find(target) != routesquickSearch[i].end()) dest.insert(i);
            for (int j = 0; j < i; j++) {
                for (int num : routesquickSearch[j]) {
                    if (routesquickSearch[i].find(num) != routesquickSearch[i].end()) {
                        graph[i].push_back(j);
                        graph[j].push_back(i);
                        break;
                    }
                }
            }
        }
        // for (auto num : dest) cout << num << endl;
        int count = 0;
        while (!q.empty()) {
            count++;
            int size = q.size();
            while (size--) {
                int cur = q.front();
                q.pop();
                if (dest.find(cur) != dest.end())
                    return count;
                for (auto nbr : graph[cur]) {
                    if (!visited[nbr]) {
                        visited[nbr] = true;
                        q.push(nbr);
                    }
                }
            }
        }
        return -1;
    }
};