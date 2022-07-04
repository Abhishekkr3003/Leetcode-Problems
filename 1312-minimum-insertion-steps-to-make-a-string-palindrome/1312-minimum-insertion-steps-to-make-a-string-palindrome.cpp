class Solution {
    vector<vector<int>>t;
    
    int solve(string &s, int lo, int hi){
        if(lo>=hi) return 0;
        if(t[lo][hi]!=-1) return t[lo][hi];
        
        if(s[lo]==s[hi]) {
            return t[lo][hi]=solve(s,lo+1,hi-1);
        }
        return t[lo][hi]=1+min(solve(s,lo+1,hi),solve(s,lo,hi-1));
    }
    
public:
    int minInsertions(string s) {
        t.resize(s.length(),vector<int>(s.length(),-1));
        return solve(s,0,s.length()-1);
    }
};