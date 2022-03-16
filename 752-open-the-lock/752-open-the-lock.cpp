/* 
    Time: O(9999)
    Space: O(9999)
    Tag: BFS
    Difficulty: M
*/

class Solution {
public:
    int openLock(vector<string> &deadends, string target) {
        if (target == "0000") return 0;
        unordered_set<string> visited;
        for (string s : deadends) {
            visited.insert(s);
        }
        if(visited.find("0000")!=visited.end()) return -1;
        queue<string> q;
        q.push("0000");
        visited.insert("0000");
        int steps = 0;

        while (!q.empty()) {
            steps++;
            int size = q.size();
            for (int i = 0; i < size; i++) {
                string cur = q.front();
                q.pop();
                string temp = cur;
                for (int i = 0; i < 4; i++) {
                    temp = cur;
                    temp[i] = '0' + ((temp[i] - '0' + 9) % 10);
                    if (visited.find(temp) == visited.end()) {
                        if (temp == target) return steps;
                        visited.insert(temp);
                        q.push(temp);
                    }
                }
                for (int i = 0; i < 4; i++) {
                    temp = cur;
                    temp[i] = '0' + ((temp[i] - '0' + 1) % 10);
                    if (visited.find(temp) == visited.end()) {
                        if (temp == target) return steps;
                        visited.insert(temp);
                        q.push(temp);
                    }
                }
            }
        }
        return -1;
    }
};