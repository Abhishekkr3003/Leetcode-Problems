/*
    Time: O(n)
    Space: O(1)
    Tag: DP (Linear DP on String)
    Difficulty: VH
    Notes: https://drive.google.com/drive/u/0/folders/1Vtkt7oEvnr_P6ZM9BrgpNt0-4ASWJhzc
*/

class Solution {
    public:
    int uniqueLetterString(string s) {
        if (s.length() == 1) return 1;
        vector<vector<int>> subtract(26, { 0,0,-1,0 });
        int f = 0, sec = 0;
        long long toBeSub=0;
        for (int i = 0;i <s.length();i++) {
            sec += f;
            sec += ((long long)(i + 1) * (i + 2)) / 2ll;
            if (subtract[s[i] - 'A'][2] != -1) {
                toBeSub += (2 * subtract[s[i] - 'A'][1]);
                toBeSub += subtract[s[i] - 'A'][3];
                subtract[s[i] - 'A'][3]+=subtract[s[i] - 'A'][1];
                subtract[s[i] - 'A'][0] = toBeSub;
                subtract[s[i] - 'A'][1] = i - subtract[s[i] - 'A'][2];
                subtract[s[i] - 'A'][2] = i;
            } else {
                subtract[s[i] - 'A'][2] = i;
                subtract[s[i] - 'A'][1] = i+1;
            }
            sec -= toBeSub;
            f = sec;
            sec = 0;
            
        }
        return f;
    }
};