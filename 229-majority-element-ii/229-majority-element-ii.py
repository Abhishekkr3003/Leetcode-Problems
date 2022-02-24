class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:
        cand1, cand2, cand1_votes, cand2_votes = 0, 1, 0, 0
        for num in nums:
            if cand1==num:
                cand1_votes+=1
            elif cand2==num:
                cand2_votes+=1
            elif cand1_votes==0:
                cand1=num
                cand1_votes=1
            elif cand2_votes==0:
                cand2=num
                cand2_votes=1
            else:
                cand1_votes-=1
                cand2_votes-=1
            # print(num,cand1,cand2,cand1_votes,cand2_votes)
        res=[]
        # print(cand1,cand2)
        if nums.count(cand1)>len(nums)//3:
            res.append(cand1)
        if nums.count(cand2) >len(nums)//3 and ((not res) or res[-1]!=cand2):
            res.append(cand2)
        return res