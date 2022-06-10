class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {        
        int n=prices.size();
        if(n==0) return 0;
        
        vector<int>t(n,0), temp(n);
        
        for(int i=0;i<k;i++){
            temp[0]=0;
            int bp=-prices[0];
            for(int j=1;j<n;j++){
                temp[j]=max({prices[j]+bp,t[j],temp[j-1]});
                bp=max(bp,t[j-1]-prices[j]);
            }
            t=temp;
        }
        return t[n-1];
    }
};