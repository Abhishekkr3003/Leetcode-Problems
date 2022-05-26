/* 
    Time: O()
    Space: O()
    Tag: 
    Difficulty: 
*/

class Solution {
    vector<int> solve(vector<int> graph[], int root, string &labels, vector<int> &res, int parent) {
        // cout<<root<<endl;
        vector<int> freq(26, 0);
        for (int nbr : graph[root]) {
            if (nbr != parent) {
                vector<int> temp = solve(graph, nbr, labels, res, root);
                for (int i = 0; i < 26; i++) freq[i] += temp[i];
            }
        }
        freq[labels[root]-'a']++;
        res[root] = freq[labels[root] - 'a'];
        return freq;
    }

public:
    vector<int> countSubTrees(int n, vector<vector<int>> &edges, string labels) {
        vector<int> graph[n];
        for (auto &edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        vector<int> res(n);
        solve(graph, 0, labels, res, -1);
        return res;
    }
};