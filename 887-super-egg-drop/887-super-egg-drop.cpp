class Solution {
    vector<vector<int>>t;
    
    int solve(int n, int k){
        if(n==0) return 0;
        if(k==1) return n;
        if(t[n][k]!=-1) return t[n][k];
        
        int res=INT_MAX;
        int lo=1, hi=n;
        int mid=0;
        while(lo<=hi){
            mid=lo+(hi-lo)/2;
            int t1=solve(mid-1,k-1);
            int t2=solve(n-mid,k);
            
            res=min(res,1+max(t1,t2));
            if(t1>t2) hi=mid-1;
            else lo=mid+1;
        }
        return t[n][k]=res;
    }
    
public:
    int superEggDrop(int k, int n) {
        t.resize(n+1, vector<int>(k+1,-1));
        return solve(n,k);
    }
};