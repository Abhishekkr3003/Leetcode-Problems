
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/* 
    Time: O(nums.size()*log(sum(nums)-min(nums)))
    Space: O(1)
    Tag: Binary Search
    Difficulty: M
*/

class Solution {
    bool checkFeas(int m, vector<int> nums, int maxSum) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > maxSum) return false;
            if (nums[i] + sum > maxSum) {
                m--;
                sum = nums[i];
                continue;
            }
            sum += nums[i];
        }
        return m <= 0 ? false : true;
    }

public:
    int splitArray(vector<int>& nums, int m) {
        int lo = *min_element(nums.begin(), nums.end()), hi = accumulate(nums.begin(), nums.end(), 0);
        int ans, mid;

        while (lo <= hi) {
            mid = lo + (hi - lo) / 2;
            if (checkFeas(m, nums, mid)) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return ans;
    }
};