class Solution {
    long long gcd(long long a, long long b){
        return b==0?a:gcd(b,a%b);
    }
public:
    int nthUglyNumber(int n, int a, int b, int c) {
        long long lo=0, hi=n*min({a,b,c});
        long long mid=0, ans=-1;
        
        long long lcmABC=(((long long)a*b*c)*gcd(c,gcd(a,b)))/(gcd(a,b)*gcd(b,c)*gcd(c,a));
        long long lcmAB=(long long)a*b/gcd(a,b);
        long long lcmBC=(long long)b*c/gcd(b,c);
        long long lcmCA=(long long)c*a/gcd(c,a);
        
        while(lo<=hi){
            mid=lo+(hi-lo)/2;
            
            long long curPos=mid/a+mid/b+mid/c-mid/lcmAB-mid/lcmBC-mid/lcmCA+mid/lcmABC;
            
            if(curPos<n) 
                lo=mid+1;
            else {
                ans=mid;
                hi=mid-1;
            }
        }
        return ans;
    }
};