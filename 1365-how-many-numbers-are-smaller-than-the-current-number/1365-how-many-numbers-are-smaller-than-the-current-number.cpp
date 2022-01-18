class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int>t(101,0);
        for(int num:nums) t[num]++;
        for(int i=1;i<=100;i++) t[i]+=t[i-1];
        for(int i=0;i<nums.size();i++) if(nums[i]) nums[i]=t[nums[i]-1];
        return nums;       
    }
};