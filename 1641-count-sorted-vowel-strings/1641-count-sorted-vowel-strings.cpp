/* 
    Time: O(n)
    Space: O(n)
    Tag: DP (State Wise)
    Difficulty: EM
*/

class Solution {
public:
    int countVowelStrings(int n) {
        vector<vector<int>>t(5, vector<int>(n));
        t[0][0]=1;
        t[1][0]=1;
        t[2][0]=1;
        t[3][0]=1;
        t[4][0]=1;
        for(int i=1;i<n;i++){
            t[0][i]=1;
            t[1][i]=t[1][i-1]+1;
            t[2][i]=t[2][i-1]+t[1][i];
            t[3][i]=t[3][i-1]+t[2][i];
            t[4][i]=t[4][i-1]+t[3][i];
        }
        return t[0][n-1]+t[1][n-1]+t[2][n-1]+t[3][n-1]+t[4][n-1];
    }
};