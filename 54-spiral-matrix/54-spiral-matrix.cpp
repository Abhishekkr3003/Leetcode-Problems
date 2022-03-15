class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& t) {
        int m=t.size();
        int n=t[0].size();
        vector<int>res;
        bool passed=false;
        for (int i = 0; i < ceil(m / 2.0); i++) {
            for (int j = i; j < n - i; j++) {
                res.push_back( t[i][j]);
                passed=true;
            }
            if(!passed) break;
            passed=false;
            for (int j = i + 1; j < m - i; j++) {
                res.push_back( t[j][n - 1 - i]);
                passed=true;
            }
            if(!passed) break;
            passed=false;
            for (int j = n - 2 - i; j >= i; j--) {
                res.push_back(t[m - 1 - i][j] );
                passed=true;
            }
            if(!passed) break;
            passed=false;
            for (int j = m - 2 - i; j > i; j--) {
                res.push_back(t[j][i]);
                passed=true;
            }
            if(!passed) break;
            passed=false;
        }

        return res;
    }
};