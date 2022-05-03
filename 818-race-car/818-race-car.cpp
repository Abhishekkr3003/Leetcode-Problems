/* 
    Time: O()
    Space: O()
    Tag: 
    Difficulty: 
*/

class Solution {
public:
    int racecar(int target) {
        set<pair<int, int>> visited;
        queue<pair<int, int>> q;
        int size = 0;
        int dist = 0;
        q.push({0, 1});
        visited.insert({0, 1});
        int threshHold = 1e4;
        while (!q.empty()) {
            size = q.size();
            dist++;
            for (int i = 0; i < size; i++) {
                int pos = q.front().first;
                int speed = q.front().second;
                // cout << pos << " " << speed << endl;
                if (pos == target) return dist - 1;
                q.pop();
                if (abs(pos + speed) < target *2 && visited.find({pos + speed, 2 * speed}) == visited.end()) {
                    q.push({pos + speed, 2 * speed});
                    visited.insert({pos + (speed), 2 * speed});
                }
                if ((speed < 0 && pos + speed < target) || (speed > 0 && pos + speed > target)) {
                    if (visited.find({pos, -(speed / abs(speed))}) == visited.end()) {
                        q.push({pos, -(speed / abs(speed))});
                        visited.insert({pos, -(speed / abs(speed))});
                    }
                }
            }
        }
        return -1;
    }
};