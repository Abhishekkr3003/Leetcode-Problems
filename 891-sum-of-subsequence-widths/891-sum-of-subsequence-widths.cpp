typedef long long ll;

/*
    Time: O(n)
    Space: O(n)
    Tag: Maths
    Difficulty: MH
*/

class Solution {
public:
    int sumSubseqWidths(vector<int>& nums) {
        int mod = 1e9 + 7;
        vector<int>pow2(nums.size());
        pow2[0] = 1;
        for (int i = 1;i < nums.size();i++) {
            pow2[i] = (pow2[i - 1] * 2ll) % mod;
        }
        int res = 0;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0;i < nums.size();i++) {
            res = (res + ((ll)nums[i] * (pow2[i] - pow2[n - 1 - i]))) % mod;
        }
        return res;
    }
};