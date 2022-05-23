/* 
    Time: O()
    Space: O()
    Tag: 
    Difficulty: 
*/

class Solution {
public:
    int longestSubsequence(vector<int> &arr, int difference) {
        unordered_map<int, int> mp;
        int res = 1;
        for (int i = 0; i < arr.size(); i++) {
            auto it = mp.find(arr[i] - difference);
            if (it == mp.end())
                mp[arr[i]] = max(mp[arr[i]], 1);
            else
                mp[arr[i]] = max(mp[arr[i]], 1 + mp[arr[i] - difference]);
            res = max(res, mp[arr[i]]);
        }
        return res;
    }
};