
typedef long long ll;

class Solution {
public:
    long long getDescentPeriods(vector<int> &prices) {
        ll res = 0;
        ll len = 1;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] - prices[i - 1] == -1)
                len++;
            else {
                res += (len * (len + 1)) / 2;
                len = 1;
            }
        }
        res += (len * (len + 1)) / 2;
        return res;
    }
};