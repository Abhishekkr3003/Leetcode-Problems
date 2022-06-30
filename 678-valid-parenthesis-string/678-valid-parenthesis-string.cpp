class Solution {
    
    bool solve(string &s, int idx, int openCount, vector<vector<int>>&t){
        if(idx==s.length()){
            return (openCount==0);
        }
        if(openCount<0) return false;
        if(t[idx][openCount]!=-1) return t[idx][openCount];
        
        if(s[idx]=='(' || s[idx]=='*') if(solve(s,idx+1,openCount+1,t)) return true;
        if(s[idx]==')' || s[idx]=='*') if(solve(s,idx+1,openCount-1,t)) return true;
        if(s[idx]=='*') if(solve(s,idx+1,openCount,t)) return true;
        
        return t[idx][openCount]=false;        
    }
    
public:
    bool checkValidString(string s) {
        vector<vector<int>>t(s.length()+1, vector<int>(s.length()+1,-1));
        return solve(s,0,0,t);
    }
};