class Solution {
    vector<int>t;
    
    int solve(int n){
        if(n<=1) return 1;
        if(t[n]!=-1) return t[n];
        
        int res=0;
        for(int i=0;i<=n-1;i++){
            res+=solve(i)*solve(n-1-i);
        }
        return t[n]=res;
    }
public:
    int numTrees(int n) {
        t.resize(n+1,-1);
        return solve(n);
    }
}; 