/* 
    Time: O()
    Space: O()
    Tag: 
    Difficulty: 
*/

class Solution {
    vector<int> parent, rank;

    int find_(int a) {
        return parent[a] == -1 ? a : parent[a] = find_(parent[a]);
    }

    void union_(int a, int b) {
        a = find_(a);
        b = find_(b);
        if (a != b) {
            if (rank[a] < rank[b]) {
                parent[a] = b;
                rank[b] += rank[a];
            } else {
                parent[b] = a;
                rank[a] += rank[b];
            }
        }
    }

    void dfs(int node, vector<int> &cluster, vector<int> graph[]) {
        cluster.push_back(node);
        for (int nbr : graph[node]) dfs(nbr, cluster, graph);
    }

public:
    string smallestStringWithSwaps(string s, vector<vector<int>> &pairs) {
        parent.resize(s.length(), -1);
        rank.resize(s.length(), 1);
        for (vector<int> &p : pairs) {
            union_(p[0], p[1]);
        }
        vector<int> graph[s.length()];
        for (int i = 0; i < s.length(); i++) {
            if (parent[i] != -1)
                graph[parent[i]].push_back(i);
        }
        for (int i = 0; i < s.length(); i++) {
            if (parent[i] == -1) {
                vector<int> cluster;
                dfs(i, cluster, graph);
                string clusterString = "";
                for (int i = 0; i < cluster.size(); i++) clusterString += s[cluster[i]];
                sort(clusterString.begin(), clusterString.end());
                sort(cluster.begin(), cluster.end());
                for (int i = 0; i < clusterString.length(); i++) {
                    s[cluster[i]] = clusterString[i];
                }
            }
        }
        return s;
    }
};