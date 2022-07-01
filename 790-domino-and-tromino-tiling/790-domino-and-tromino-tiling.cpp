class Solution {
    vector<int>f;
    vector<int>p;
    int mod=1e9+7;
    
    int partCase(int n){
        if(n<=0) return 0;
        if(p[n]!=-1) return p[n];
                
        return p[n]=((long long)partCase(n-1)+fullCase(n-2))%mod;
    }
    
    int fullCase(int n){
        if(n==0) return 1;
        if(n<0) return 0;
        if(f[n]!=-1) return f[n];
        
        return f[n]=((long long)fullCase(n-1)+fullCase(n-2)+2*partCase(n-1))%mod;
    }
    
public:
    int numTilings(int n) {
        f.resize(n+1,-1);
        p.resize(n+1,-1);
        
        return fullCase(n);
    }
};