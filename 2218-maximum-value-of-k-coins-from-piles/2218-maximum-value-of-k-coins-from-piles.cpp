/*
    Time: O(sum(piles[i].length)*k)
    Space: O(len(piles)*k)
    Tag: DP (Subsets Recursion Memoization) (Kind of Knapsack)
    Difficulty: H
*/


class Solution {
    vector<vector<int>>piles;
    int solve(vector<vector<int>>& t, int pileNo, int k) {
        if (k == 0) return 0;
        if (pileNo >= piles.size()) return INT_MIN;
        if (t[pileNo][k] != -1) return t[pileNo][k];
        int res = solve(t, pileNo + 1, k);
        for (int i = 0; i < min((int)(piles[pileNo].size()), k); i++) {
            res = max(res, piles[pileNo][i] + solve(t, pileNo + 1, k - i - 1));
        }
        return t[pileNo][k] = res;
    }

public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        vector<vector<int>>t(piles.size() + 1, vector<int>(k + 1, -1));
        for (int i = 0; i < piles.size(); i++) {
            for (int j = 1; j < piles[i].size(); j++) {
                piles[i][j] += piles[i][j - 1];
            }
        }
        this->piles = piles;
        return solve(t, 0, k);
    }
};