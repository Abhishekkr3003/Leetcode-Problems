
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/* 
    Time: O(N!)
    Space: O(N) because of Map
    Tag: Backtraching and hashmap
    Difficulty: M
*/

class Solution {
    vector<vector<int>> res;
    int n;

    void solve(unordered_map<int, int> &mp, vector<int> &cur) {
        if (cur.size() == n) {
            res.push_back(cur);
            return;
        }
        for (auto it = mp.begin(); it != mp.end(); it++) {
            if (it->second > 0) {
                cur.push_back(it->first);
                it->second = it->second - 1;
                solve(mp, cur);
                cur.pop_back();
                it->second = it->second + 1;
            }
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int> &nums) {
        unordered_map<int, int> mp;
        n = nums.size();
        for (int num : nums) mp[num]++;
        vector<int> cur;
        solve(mp, cur);
        return res;
    }
};