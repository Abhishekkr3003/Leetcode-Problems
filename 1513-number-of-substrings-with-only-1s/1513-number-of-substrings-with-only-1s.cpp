class Solution {
public:
    int numSub(string s) {
        int mod=1e9+7;
        long long res=0;
        long long curCount=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1') curCount++;
            else {
                res=(res+(((curCount%mod*(curCount+1)%mod))>>1))%mod;
                curCount=0;
            }
        }
        res=(res+(((curCount%mod*(curCount+1)%mod))>>1))%mod;
        return res;
    }
};