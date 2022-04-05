/*
    Time: O()
    Space: O()
    Tag:
    Difficulty:
*/

class Solution {
public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int>mp;
        vector<int>t;

        for (int i = 0;i < target.size();i++) mp[target[i]] = i + 1;
        for (int num : arr) {
            if (mp.find(num) == mp.end()) continue;
            auto it = lower_bound(t.begin(), t.end(), mp[num]);
            if (it == t.end()) t.push_back(mp[num]);
            else t[it - t.begin()] = mp[num];
        }
        return target.size() - t.size();
    }
};