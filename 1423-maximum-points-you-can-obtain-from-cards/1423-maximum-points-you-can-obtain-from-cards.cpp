/* 
    Time: O()
    Space: O()
    Tag: 
    Difficulty: 
*/

class Solution {
public:
    int maxScore(vector<int> &cardPoints, int k) {
        int n = cardPoints.size();
        vector<int> fromLeft(n + 1), fromRight(n + 1);
        fromRight[0] = fromLeft[0] = 0;
        for (int i = 0; i < n; i++) {
            fromLeft[i + 1] = fromLeft[i] + cardPoints[i];
            fromRight[i + 1] = fromRight[i] + cardPoints[n - 1 - i];
        }
        int res = 0;
        for (int i = 0; i <= k; i++) {
            res = max(res, fromLeft[i] + fromRight[k - i]);
        }
        return res;
    }
};