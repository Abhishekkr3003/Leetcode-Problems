class Solution {
public:
    int fib(int n) {
        if(n<2) return n;
        int f=1,s=1;
        n-=2;
        int t;
        while(n--){
            t=f+s;
            f=s;
            s=t;
        }
        return t;
    }
};