typedef long long ll;

/* 
    Time: O()
    Space: O()
    Tag: 
    Difficulty: 
*/

class Solution {
    vector<vector<int>> t;
    int mod = 1e9 + 7;

    ll solve(int goal, int used, int unused, int k) {
        if(goal<unused) return 0;
        if (goal == 0) {
            // cout<<goal<<" "<<used<<" "<<unused<<endl;
            if (unused > 0) return 0;
            // cout<<"here\n";
            return 1;
        }
        if (t[goal][used] != -1) return t[goal][used];
        ll usingUsed=(max(0,used-k)>0?max(0, used - k) * solve(goal - 1, used, unused, k):0);
        ll usingNew=(unused>0?unused * solve(goal - 1, used + 1, unused - 1, k):0);
        t[goal][used] = (usingUsed + usingNew) % mod;
        // cout<<goal<<" "<<used<<" "<<unused<<" "<<t[goal][used]<<endl;
        return t[goal][used];
    }

public:
    int numMusicPlaylists(int n, int goal, int k) {
        t.resize(goal + 1, vector<int>(n + 1, -1));
        return solve(goal, 0, n, k);
    }
};