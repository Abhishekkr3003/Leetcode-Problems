class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cand=nums[0];
        int votes=1;
        
        for(int i=1;i<nums.size();i++){
            if(nums[i]==cand) votes++;
            else{
                votes--;
                if(votes==0) {
                    cand=nums[i];
                    votes=1;
                }
            }
        }
        return cand;
        
    }
};