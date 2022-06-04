class Solution {
public:
    int countOdds(int lo, int hi) {
        int range=hi-lo+1;
        if((range&1)==0) return range/2;
        if(lo&1) return 1+range/2;
        return range/2;
    }
};