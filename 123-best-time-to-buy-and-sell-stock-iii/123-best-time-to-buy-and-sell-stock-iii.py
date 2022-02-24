class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        first_trans=[0 for i in range(len(prices)+1)]
        max_so_far=-prices[0]
        for i in range(1,len(prices)):
            first_trans[i+1]=max(first_trans[i], prices[i]+max_so_far)
            max_so_far=max(max_so_far,-prices[i])
        sec_trans=[0 for i in range(len(prices)+1)]
        max_so_far=-prices[0]
        for i in range(1,len(prices)):
            sec_trans[i+1]=max(sec_trans[i],prices[i]+max_so_far)
            max_so_far=max(max_so_far,first_trans[i]-prices[i])
        return sec_trans[-1]
            