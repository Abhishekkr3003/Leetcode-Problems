typedef long long ll;
class Solution {
public:
    int nthUglyNumber(int n) {
        ll maxEle = n;
        ll f = 0, s = 0, th = 0;
        vector<ll> uglyNums(maxEle);
        uglyNums[0] = 1;
        for (int i = 1; i < maxEle; i++) {
            if ((2 * uglyNums[f] <= 3 * uglyNums[s]) && (2 * uglyNums[f] <= 5 * uglyNums[th])) {
                uglyNums[i] = 2 * uglyNums[f];
                f++;
            } else if ((3 * uglyNums[s] <= 2 * uglyNums[f]) && (3 * uglyNums[s] <= 5 * uglyNums[th])) {
                uglyNums[i] = 3 * uglyNums[s];
                s++;
            } else {
                uglyNums[i] = 5 * uglyNums[th];
                th++;
            }
            while ((2 * uglyNums[f]) <= uglyNums[i]) f++;
            while ((3 * uglyNums[s]) <= uglyNums[i]) s++;
            while ((5 * uglyNums[th]) <= uglyNums[i]) th++;
        }   
        return uglyNums.back();
    }
};