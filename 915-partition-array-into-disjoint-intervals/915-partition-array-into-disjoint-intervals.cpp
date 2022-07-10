class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int overallMax=nums[0];
        int curMax=nums[0];
        int res=0;
        
        for(int i=1;i<nums.size();i++){
            if(nums[i]<curMax){
                res=i;
                curMax=overallMax;
            }
            overallMax=max(overallMax,nums[i]);
        }
        return res+1;
    }
};