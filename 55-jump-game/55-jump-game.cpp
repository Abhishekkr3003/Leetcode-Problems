class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach=nums[0];
        int curReach=nums[0];
        
        if(nums.size()==1) return true;
        if(nums[0]==0) return false;
        
        for(int i=1;i<nums.size();i++){
            maxReach=max(maxReach,i+nums[i]);
            if(maxReach>=nums.size()-1) return true;
            if(i==curReach){
                if(maxReach<=i) return false;
                curReach=maxReach;
                maxReach=0;
            }
        }
        return true;
    }
};