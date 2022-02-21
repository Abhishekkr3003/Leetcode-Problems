class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int major=nums[0];
        int votes=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==major) votes++;
            else votes--;
            if(votes==-1) {
                major=nums[i];
                votes=1;
            }
        }
        return major;
    }
};