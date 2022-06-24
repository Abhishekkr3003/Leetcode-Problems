class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int b1=-prices[0], s1=0, b2=INT_MIN, s2=0;
        int newB1=0, newS1=0, newB2=0, newS2=0;
        
        for(int i=1;i<prices.size();i++){
            newB1=max(b1,-prices[i]);
            newS1=max(s1,prices[i]+b1);
            newB2=max(b2,s1-prices[i]);
            newS2=max(s2,prices[i]+b2);
            
            b1=newB1, s1=newS1, b2=newB2, s2=newS2;
        }
        
        return max(s1,s2);
    }
};