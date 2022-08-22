class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0) return false;
        double res=log(n)/log(4);
        if(res-(int)res>0) return false;
        return true;
    }
};