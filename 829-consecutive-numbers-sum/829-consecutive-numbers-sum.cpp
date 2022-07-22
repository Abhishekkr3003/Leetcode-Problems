class Solution {
public:
    int consecutiveNumbersSum(int n) {
        int upperLimit=sqrt(2*n+0.25)-0.5;
        int res=0;
        for(int k=1;k<=upperLimit;k++){
            if(((2*n-k*(k+1))/2)%k==0) res++;
        }
        return res;
    }
};