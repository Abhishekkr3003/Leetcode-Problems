/* 
    Time: O(n)
    Space: O(1)
    Tag: DP, Based on number of ways to continue the previous strings
    Difficulty: H
*/

class Solution {
public:
    int distinctSubseqII(string s) {
        vector<int> t(26, 0);
        int mod=1e9+7;
        long long sum = 0;
        for (char &ch : s) {
            sum = 0;
            for (int i = 0; i < 26; i++) {
                sum = (sum+ t[i])%mod;
            }
            t[ch - 'a'] = (sum + 1)%mod;
        }
        sum = 0;
        for (int i = 0; i < 26; i++) {
            sum = (sum+ t[i])%mod;
        }
        return sum;
    }
};