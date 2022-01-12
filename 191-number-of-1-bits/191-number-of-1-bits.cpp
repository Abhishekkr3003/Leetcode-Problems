class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count=0;
        while(n){
            int bit=n&(-n);
            n=n^bit;
            count++;
        }
        return count;
    }
};