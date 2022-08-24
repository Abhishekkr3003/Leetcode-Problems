class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0) return false;
        double res=log10(n)/log10(3);
        // cout<<res<<" "<<(int)res<<endl;
        if(res-(int)res>0) return false;
        return true;
    }
};