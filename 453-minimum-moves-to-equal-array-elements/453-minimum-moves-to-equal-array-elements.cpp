class Solution {
public:
    int minMoves(vector<int> &nums) {
        int minEle = *min_element(nums.begin(), nums.end());
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            res += nums[i] - minEle;
        }
        return res;
    }
};