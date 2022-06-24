class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int b=-prices[0],s=0,c=0, newB=0, newS=0, newC=0;
        
        for(int i=1;i<prices.size();i++){
            newB=max(b,c-prices[i]);
            newS=max(s,b+prices[i]);
            newC=max(c,s);
            
            b=newB;
            c=newC;
            s=newS;
        }
        
        return max({b,s,c});
    }
};