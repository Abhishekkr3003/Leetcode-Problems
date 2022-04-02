typedef long long ll;

/*
    Time: O()
    Space: O()
    Tag:
    Difficulty:
*/

class Solution {
    vector<vector<int>>t;
    vector<int>jobDiff;

    int solve(int index, int day, int maxD) {
        if(day>maxD) return -1;
        if (index >= jobDiff.size()) {
            if (day == maxD) return 0;
            return -1;
        }
        if (t[index][day] != -2) return t[index][day];
        int res = INT_MAX;
        int maxTillNow = INT_MIN+1;
        for (int i = index;i < jobDiff.size();i++) {
            maxTillNow = max(maxTillNow, jobDiff[i]);
            int temp = solve(i + 1, day + 1, maxD);
            if (temp != -1) res = min(res, maxTillNow + temp);
        }
        return t[index][day] = ((res == INT_MAX) ? -1 : res);
      
    }
    
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        t.resize(jobDifficulty.size() + 1, vector<int>(d + 1, -2));
        this->jobDiff = jobDifficulty;
        return solve(0, 0, d);
    }
};