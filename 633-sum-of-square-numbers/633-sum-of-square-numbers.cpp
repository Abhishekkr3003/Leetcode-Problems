class Solution {
public:
    bool judgeSquareSum(int c) {
        for(int i=0;(long long)i*i<=c;i++){
            int rest=c-i*i;
            double root=sqrt(rest);
            if(floor(root)==root) return true;
        }
        return false;
    }
};