class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res=0;
        int curCount=0;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1) curCount++;
            else curCount=0;
            res=max(curCount,res);
        }
        
        return res;
    }
};