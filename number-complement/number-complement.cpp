class Solution {
public:
    int findComplement(int num) {
        int res=0,i=0;
        while(num){
            bool bit=num&1;
            res+=((!bit)<<i++);
            num=num>>1;
        }
        return res;
    }
};