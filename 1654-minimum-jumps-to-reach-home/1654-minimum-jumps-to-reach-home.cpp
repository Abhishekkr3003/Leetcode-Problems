/* 
    Time: O((n+e)log(n))
    Space: O(n)
    Tag: BFS
    Difficulty: M 
*/

class Solution {
public:
    int minimumJumps(vector<int> &forbidden, int a, int b, int x) {
        set<pair<int,bool>>visited;
        for (int num : forbidden) {
            visited.insert({num,true});
            visited.insert({num,false});
        };
        queue<pair<int, bool>> q;

        q.push({0, true});
        int steps = 0;
        if(x==0) return 0;
        visited.insert({0,true});
        visited.insert({0,false});
        while (!q.empty()) {
            steps++;
            int size=q.size();
            for(int i=0;i<size;i++){
                int node = q.front().first;
                bool back = q.front().second;
                q.pop();
                if (back && node >= b && visited.find({node-b,false})==visited.end()) {
                    visited.insert({node-b,false});
                    q.push({node - b, false});
                    if (node - b == x) return steps;
                }
                if (visited.find({node+a,true})==visited.end() && node - x < 4001) {
                    visited.insert({node+a,true});
                    q.push({node + a, true});
                    if (node + a == x) return steps;
                }
            }
                        
        }
        return -1;
    }
};