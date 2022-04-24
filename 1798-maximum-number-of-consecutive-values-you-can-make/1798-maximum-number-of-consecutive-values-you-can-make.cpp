class Solution {
public:
    int getMaximumConsecutive(vector<int> &coins) {
        sort(coins.begin(), coins.end());
        int curMax = 1;
        for (int i=0; i < coins.size(); i++) {
            if (coins[i] <= curMax)
                curMax = curMax + coins[i];
            else {
                break;
            }
        }
        return curMax;
    }
};