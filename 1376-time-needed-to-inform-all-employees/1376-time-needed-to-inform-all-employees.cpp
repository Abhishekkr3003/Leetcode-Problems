/* 
    Time: O()
    Space: O()
    Tag: 
    Difficulty: 
*/

class Solution {

    int dfs(vector<vector<int>> &gr, vector<int> &time, int node) {
        int maxTime = 0;
        int maxTransferTime = 0;
        for (int nbr : gr[node]) {
            maxTime = max(maxTime, dfs(gr, time, nbr));
        }
        return maxTime + time[node];
    }

public:
    int numOfMinutes(int n, int headID, vector<int> &manager, vector<int> &informTime) {
        vector<vector<int>> gr(n);
        for (int i = 0; i < manager.size(); i++) {
            if (manager[i] != -1)
                gr[manager[i]].push_back(i);
        }
        return dfs(gr, informTime, headID);
    }
};