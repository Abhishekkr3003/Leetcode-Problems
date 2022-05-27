/* 
    Time: O()
    Space: O()
    Tag: 
    Difficulty: 
*/

class Solution {
    bool possible(vector<int> &nums, int maxOperations, int curMax) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > curMax) maxOperations -= ceil((double)nums[i] / curMax) - 1;
            if (maxOperations < 0) return false;
        }
        return true;
    }

public:
    int minimumSize(vector<int> &nums, int maxOperations) {
        int lo = 1, hi = *max_element(nums.begin(), nums.end());
        int mid = 0, ans = hi;
        while (lo <= hi) {
            mid = lo + (hi - lo) / 2;
            if (possible(nums, maxOperations, mid)) {
                ans = mid;
                hi = mid - 1;
            } else
                lo = mid + 1;
        }
        return ans;
    }
};