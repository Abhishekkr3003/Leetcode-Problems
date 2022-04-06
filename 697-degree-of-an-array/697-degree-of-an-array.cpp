/*
    Time: O()
    Space: O()
    Tag:
    Difficulty:
*/

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, vector<int>>mp;
        int maxFreq = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (mp.find(nums[i]) != mp.end()) {
                mp[nums[i]][0]++;
                mp[nums[i]][2] = i;
            }
            else {
                mp[nums[i]].push_back(1);
                mp[nums[i]].push_back(i);
                mp[nums[i]].push_back(i);
            }
            maxFreq = max(maxFreq, mp[nums[i]][0]);
        }
        int res = INT_MAX;
        for (auto p : mp) {
            if (p.second[0] == maxFreq) res = min(res, p.second[2] - p.second[1] + 1);
        }
        return res;
    }
};