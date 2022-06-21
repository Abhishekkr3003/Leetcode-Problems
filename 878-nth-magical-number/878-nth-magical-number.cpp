class Solution {
    
    long long gcd(long long a, long long b){
        return b==0?a:gcd(b,a%b);
    }
    
public:
    int nthMagicalNumber(int n, int a, int b) {
        long long lo=0, hi=LLONG_MAX;
        long long mid=0, ans=-1;
        
        long long c=a*b/gcd(a,b);
        
        while(lo<=hi){
            mid=lo+(hi-lo)/2;
            
            long long curPos=mid/a+mid/b-mid/c;
            
            if(curPos<n) 
                lo=mid+1;
            else {
                ans=mid;
                hi=mid-1;
            }
        }
        int mod=1e9+7;;
        return ans%mod;
    }
};