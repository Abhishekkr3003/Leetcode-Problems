class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int b=-prices[0], s=0;
        int newB=0, newS=0;
        
        for(int i=1;i<prices.size();i++){
            newB=max(b,s-prices[i]);
            newS=max(s,b+prices[i]-fee);
            
            b=newB, s=newS;
        }
        return s;        
    }
};