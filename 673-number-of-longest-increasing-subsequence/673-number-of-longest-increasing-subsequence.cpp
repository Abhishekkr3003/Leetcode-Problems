#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
public:
    int findNumberOfLIS(vector<int> &nums) {
        vector<pair<int, int>> t;
        t.push_back({1, 1});
        int maxLen = 0, count = 0;
        for (int i = 1; i < nums.size(); i++) {
            // cout << "i:" << i << endl;
            maxLen = 0;
            count = 0;
            for (int j = i - 1; j >= 0; j--) {
                if (nums[j] < nums[i]) {
                    maxLen = max(maxLen, t[j].first);
                }
            }
            for (int j = i - 1; j >= 0; j--) {
                if (nums[j] < nums[i] && maxLen == t[j].first) {
                    count += t[j].second;
                }
            }
            // cout << "maxLen: " << maxLen<<"\n";
            // cout << count << "\n";

            count ? t.push_back({maxLen + 1, count}) : t.push_back({maxLen + 1, 1});
        }
        maxLen = 0;
        count = 0;
        for (int j = nums.size() - 1; j >= 0; j--) {
            maxLen = max(maxLen, t[j].first);
        }
        for (int j = nums.size() - 1; j >= 0; j--) {
            if (maxLen == t[j].first) {
                count += t[j].second;
            }
        }
        return count;
    }
};