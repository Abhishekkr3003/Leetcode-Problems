class Solution {
    long long t[100001][3][3];
    
    long long solve(string &s, int idx, int pos, int prev){
        if(pos==3) return 1;
        if(idx>=s.length()) return 0;
        
        if(t[idx][prev+1][pos]!=-1) return t[idx][prev+1][pos];
        
        long long res=0;
        
        res+=solve(s,idx+1,pos,prev);
        
        if(s[idx]-'0'!=prev){
            res+=solve(s,idx+1,pos+1,s[idx]-'0');
        }
        
        return t[idx][prev+1][pos]=res;
    }
    
public:
    long long numberOfWays(string s) {
        
        memset(t,-1,sizeof(t));
        return solve(s,0,0,-1);
        
    }
};