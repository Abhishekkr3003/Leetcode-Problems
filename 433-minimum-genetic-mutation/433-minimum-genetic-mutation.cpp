/* 
    Time: O(n+e)
    Space: O(n)
    Tag: BFS
    Difficulty: M
*/

class Solution {

public:
    int minMutation(string start, string end, vector<string> &bank) {
        if (start == end) return 0;
        int i = 0;
        for (; i < bank.size(); i++) {
            if (start == bank[i]) {
                break;
            }
        }
        queue<int> q;
        vector<bool> visited(bank.size(),false);
        if (i < bank.size()) visited[i] = 1;
        else {
            bank.push_back(start);
            visited.push_back(1);
        }
        q.push(i);
        int dist = 0;
        while (!q.empty()) {
            dist++;
            int size=q.size();
            for (int i = 0; i < size; i++)
            {
                string node = bank[q.front()];
                q.pop();
                for (int i = 0; i < bank.size();i++){
                    if (!visited[i] && ((node[0] != bank[i][0]) + (node[1] != bank[i][1]) + (node[2] != bank[i][2]) + (node[3] != bank[i][3]) + (node[4] != bank[i][4]) + (node[5] != bank[i][5]) + (node[6] != bank[i][6]) + (node[7] != bank[i][7]))==1){
                        if (bank[i] == end) return dist;
                        visited[i] = true;
                        q.push(i);
                    }
                }
            }
        }
        return -1;
    }
};