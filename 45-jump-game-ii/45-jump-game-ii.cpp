class Solution {
public:
    int jump(vector<int>& nums) {
        int steps=1;
        int maxReach=nums[0];
        int curReach=nums[0];
        
        if(nums.size()==1) return 0;
        if(maxReach>=nums.size()-1) return steps;
        
        for(int i=1;i<nums.size()-1;i++){
            maxReach=max(maxReach,i+nums[i]);
            if(maxReach>=nums.size()-1) return steps+1;
            if(i==curReach){
                steps++;
                curReach=maxReach;
                maxReach=0;
            }
        }
        return 0;
    }
};