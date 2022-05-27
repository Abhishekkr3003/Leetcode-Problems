/* 
    Time: O()
    Space: O()
    Tag: 
    Difficulty: 
*/

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int> &nums, int k) {
        set<pair<int, int>, greater<pair<int, int>>> inc;
        set<pair<int, int>> dec;
        vector<double> res;
        res.reserve(nums.size() - k + 1);
        vector<bool> location(nums.size());
        for (int i = 0; i < k; i++) {
            if (inc.size() == dec.size()) {
                if (!dec.empty() && dec.begin()->first < nums[i]) {
                    inc.insert(*dec.begin());
                    location[dec.begin()->second] = 0;
                    dec.erase(dec.begin());
                    dec.insert({nums[i], i});
                    location[i] = 1;
                } else {
                    inc.insert({nums[i], i});
                    location[i] = 0;
                }
            } else {
                if (!inc.empty() && nums[i] < inc.begin()->first) {
                    dec.insert(*inc.begin());
                    location[inc.begin()->second] = 1;
                    inc.erase(inc.begin());
                    inc.insert({nums[i], i});
                    location[i] = 0;
                } else {
                    dec.insert({nums[i], i});
                    location[i] = 1;
                }
            }
        }
        if (k & 1)
            res.push_back(inc.begin()->first);
        else
            res.push_back(((long long)dec.begin()->first + inc.begin()->first) / 2.0);
        for (int i = k; i < nums.size(); i++) {
            if (!location[i - k]) {
                inc.erase({nums[i - k], i - k});
                if (inc.size() < dec.size()) {
                    location[dec.begin()->second]=0;
                    inc.insert(*dec.begin());
                    dec.erase(dec.begin());
                    
                }
            } else {
                dec.erase({nums[i - k], i - k});
                if (dec.size() + 1 < inc.size()) {
                    location[inc.begin()->second]=1;
                    dec.insert(*inc.begin());
                    inc.erase(inc.begin());
                }
            }
            if (inc.size() == dec.size()) {
                if (!dec.empty() && dec.begin()->first < nums[i]) {
                    inc.insert(*dec.begin());
                    location[dec.begin()->second] = 0;
                    dec.erase(dec.begin());
                    dec.insert({nums[i], i});
                    location[i] = 1;
                } else {
                    inc.insert({nums[i], i});
                    location[i] = 0;
                }
            } else {
                if (!inc.empty() && nums[i] < inc.begin()->first) {
                    dec.insert(*inc.begin());
                    location[inc.begin()->second] = 1;
                    inc.erase(inc.begin());
                    inc.insert({nums[i], i});
                    location[i] = 0;
                } else {
                    dec.insert({nums[i], i});
                    location[i] = 1;
                }
            }
            if (k & 1)
                res.push_back(inc.begin()->first);
            else
                res.push_back(((long long)dec.begin()->first + inc.begin()->first) / 2.0);
        }
        return res;
    }
};