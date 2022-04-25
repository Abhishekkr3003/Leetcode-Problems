/* 
    Time: O(n)
    Space: O(n)
    Tag: Array Manipulation, Prefix, Sufix manipilation
    Difficulty: MH
*/

class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int> &security, int time) {
        int n = security.size();
        vector<int> leftSide(n), righSide(n);
        leftSide[0] = 0;
        for (int i = 1; i < n; i++) {
            if (security[i - 1] >= security[i])
                leftSide[i] = leftSide[i - 1];
            else
                leftSide[i] = i;
        }
        righSide[n - 1] = n - 1;
        for (int i = n - 2; i >= 0; i--) {
            if (security[i + 1] < security[i])
                righSide[i] = i;
            else
                righSide[i] = righSide[i + 1];
        }
        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (leftSide[i] <= i - time && righSide[i] >= i + time) res.push_back(i);
        }
        return res;
    }
};