/*
    Time: O()
    Space: O()
    Tag:
    Difficulty:
*/


class Solution {
    vector<vector<int>>piles;
    int solve(vector<vector<int>>& t, int pileNo, int k) {
        // cout<<pileNo<<" "<<k<<endl;
        if (k == 0) {
            // cout<<"returning zero";
            return 0;
        }
        if (pileNo >= piles.size()) return INT_MIN;
        // cout<<"here\n";
        if (t[pileNo][k] != -1) return t[pileNo][k];
        int res = solve(t, pileNo + 1, k);
        // cout<<"There "<<pileNo<<endl;
        for (int i = 0; i < min((int)(piles[pileNo].size()), k); i++) {
            // cout<<"Loop: "<<i<<endl;
            res = max(res, piles[pileNo][i] + solve(t, pileNo + 1, k - i - 1));
            // cout<<i<<" res "<<res<<endl;
            // cout<<"here2\n";
        }
        // cout<<"here3\n";
        // cout<<"Before Return "<<pileNo<<" "<<k<<endl;
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