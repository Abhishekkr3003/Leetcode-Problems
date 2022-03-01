class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>res(n+1,0);
        for(int i=0;i<=n;i++){
            int temp=i;
            while(temp){
                res[i]++;
                temp&=(temp-1);
            }
        }
        return res;
    }
};