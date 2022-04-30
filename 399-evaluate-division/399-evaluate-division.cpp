class Solution {
public:
    vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries) {
        unordered_map<string, vector<pair<string, double>>> graph;
        for (int i = 0; i < equations.size(); i++) {
            graph[equations[i][0]].push_back({equations[i][1], values[i]});
            graph[equations[i][1]].push_back({equations[i][0], 1.0 / values[i]});
        }
        vector<double> res;
        queue<pair<string, double>> q;
        unordered_set<string> visited;
        bool found;
        for (vector<string> &query : queries) {
            if(graph.find(query[0])==graph.end() || graph.find(query[1])==graph.end()){
                res.push_back(-1);
                continue;
            }
            while (!q.empty()) q.pop();
            q.push({query[0], 1});
            visited.clear();
            visited.insert(query[0]);
            found = false;
            while (!q.empty()) {
                string curNode = q.front().first;
                double val = q.front().second;
                q.pop();
                if (curNode == query[1]) {
                    res.push_back(val);
                    found = true;
                    break;
                }
                for (auto nbr : graph[curNode]) {
                    if (visited.find(nbr.first) == visited.end()) {
                        visited.insert(nbr.first);
                        q.push({nbr.first, val * nbr.second});
                    }
                }
            }
            if (!found) res.push_back(-1);
        }
        return res;
    }
};