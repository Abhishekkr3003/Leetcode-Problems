class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        if(right>(2ll*left-1)) return 0;
        int res=INT_MAX;
        for(long long i=left;i<=right;i++) res&=i;
        return res;
    }
};