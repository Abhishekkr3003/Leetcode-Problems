/* 
    Time: O()
    Space: O()
    Tag: 
    Difficulty: 
*/

class Solution {
public:
    int minimumJumps(vector<int> &forbidden, int a, int b, int x) {
        vector<vector<bool>>visited(20003,vector<bool>(2,false));
        for (int num : forbidden) visited[num][0]=visited[num][1]=true;
        queue<pair<int, bool>> q;

        q.push({0, true});
        int steps = 0;
        if(x==0) return 0;
        visited[0][0]=visited[0][1]=true;
        while (!q.empty()) {
            steps++;
            int size=q.size();
            for(int i=0;i<size;i++){
                int node = q.front().first;
                bool back = q.front().second;
                q.pop();
                if (back && node >= b && !visited[node-b][0]) {
                    visited[node-b][0]=true;
                    q.push({node - b, false});
                    if (node - b == x) return steps;
                }
                if (!visited[node+a][1] && node - x < 5001) {
                    visited[node+a][1]=true;
                    q.push({node + a, true});
                    if (node + a == x) return steps;
                }
            }
                        
        }
        return -1;
    }
};