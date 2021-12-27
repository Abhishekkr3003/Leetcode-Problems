class Solution {
public:
    int bitwiseComplement(int num) {
        if(num==0) return 1;
        int res=0,i=0;
        while(num){
            bool bit=num&1;
            res+=((!bit)<<i++);
            num=num>>1;
        }
        return res;
    }
};