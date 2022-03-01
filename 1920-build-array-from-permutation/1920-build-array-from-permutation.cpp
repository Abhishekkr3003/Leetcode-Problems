class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            nums[i]=(nums[nums[i]]%1001)*1001+nums[i];
        }
        for(int i=0;i<nums.size();i++){
            nums[i]/=1001;
        }
        return nums;
    }
};