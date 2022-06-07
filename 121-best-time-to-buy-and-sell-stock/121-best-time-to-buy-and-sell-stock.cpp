class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sellAt=prices.back();
        int profit=0;
        for(int i=prices.size()-1;i>=0;i--){
            if(prices[i]>sellAt) sellAt=prices[i];
            else profit=max(profit,sellAt-prices[i]);
        }
        return profit;
    }
};