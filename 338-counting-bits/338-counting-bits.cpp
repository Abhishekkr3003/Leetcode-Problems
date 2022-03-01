class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>res(n+1,0);
        if(n==0) return res;
        res[1]=1;
        for(int i=2;i<=n;i++){
            res[i]=res[i/2]+(i&1);
        }
        return res;
    }
};