class Solution {
public:
    double myPow(double x, int n) {
        if(x==0 || x==1) return x;
        if(n==0) return 1;
        if(n<0) return (1/x)*myPow(1/x,-(n+1));
        
        double res=x;
        while(n>1){
            if(n&1) res*=x;
            res*=x;
            // cout<<n<<" "<<res<<endl;
            x*=x;
            n/=2;            
        }
        return res;        
    }
};