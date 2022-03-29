/*
    Time: O(nlogn)
    Space: O(n)
    Tag: Prefix, Suffix, HashMap, Binary Search
    Difficulty: H
*/

typedef long long ll;

class Solution {
public:
    int waysToPartition(vector<int>& nums, int k) {
        int n = nums.size();
        vector<ll>prefix(n);
        vector<ll>suffix(n);
        unordered_map<ll, vector<int>>diff;
        prefix[0] = nums[0];
        suffix[n - 1] = nums[n - 1];
        for (int i = 1; i < nums.size(); i++) {
            prefix[i] = prefix[i - 1] + nums[i];
            suffix[n - i - 1] = suffix[n - i] + nums[n - i - 1];
        }
        for (int i = 0; i < n - 1; i++) {
            diff[prefix[i] - suffix[i + 1]].push_back(i);
        }
        int res = diff[0].size();
        for (int i = 0; i < n; i++) {
            int later=0, prev=0;
            if (!diff[nums[i] - k].empty()) {
                later = diff[nums[i] - k].size() - (lower_bound(diff[nums[i] - k].begin(), diff[nums[i] - k].end(), i) - diff[nums[i] - k].begin());
            }
            if(!diff[k-nums[i]].empty()){
                prev = (lower_bound(diff[k-nums[i]].begin(), diff[k-nums[i]].end(), i) - diff[k-nums[i]].begin());
            }
            res = max(res, later + prev);
        }
        return res;
    }
};