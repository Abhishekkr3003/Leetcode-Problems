/* 
    Time: O(nlogn) 
    Space: O(n)
    Tag: DP with Map, build next state from previous state | Instead of map we can use stack to find the greatest smallest and smallest greatest elements.
    Difficulty: H
*/

class Solution {
public:
    int oddEvenJumps(vector<int> &arr) {
        map<int, set<int>> pos;
        vector<pair<int, int>> nextJump(arr.size()); // first->odd || second->even
        for (int i = 0; i < arr.size(); i++) {
            pos[arr[i]].insert(i);
        }
        for (int i = 0; i < arr.size(); i++) {
            auto it = pos.find(arr[i]);
            if (it->second.size() > 1) {
                it->second.erase(it->second.begin());
                nextJump[i].first = *(it->second.begin());
                nextJump[i].second = nextJump[i].first;
            } else {
                if (it == pos.begin()) {
                    nextJump[i].second = -1;
                } else {
                    auto it2 = prev(it);
                    nextJump[i].second = *(it2->second.begin());
                }
                auto it2 = next(it);
                if (it2 == pos.end()) {
                    nextJump[i].first = -1;
                } else {
                    nextJump[i].first = *(it2->second.begin());
                }
                pos.erase(it);
            }
        }
        vector<pair<int, int>> t(arr.size(), {1, 0});
        for (int i = 0; i < arr.size() - 1; i++) {
            if (t[i].first) {
                if (nextJump[i].first != -1) t[nextJump[i].first].second += t[i].first;
            }
            if (t[i].second) {
                if (nextJump[i].second != -1) t[nextJump[i].second].first += t[i].second;
            }
        }
        return t[arr.size() - 1].first + t[arr.size() - 1].second;
    }
};