class Solution {
public:
    int reachNumber(int target) {
        target=abs(target);
        int n=ceil((-1.0+sqrt(1+8.0*target))/2.0);
        int sum=(n*(n+1))/2;
        if(sum==target) return n;
        if(((sum-target)&1)==0) return n;
        sum+=(n+1);
        if(((sum-target)&1)==0) return n+1;
        return n+2;
    }
};