class Solution {
public:
    int minPatches(vector<int> &nums, int n) {
        int res = 0;
        long long curMax = 1;
        int idx = 0;
        while (curMax <= n) {
            if (idx<nums.size() && curMax >= nums[idx])
                curMax = curMax + nums[idx++];
            else {
                res++;
                curMax += curMax;
            }
        }
        return res;
    }
};