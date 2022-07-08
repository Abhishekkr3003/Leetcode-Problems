class Solution {
public:
    int findMin(vector<int>& nums) {
        int lo=1, hi=nums.size()-2;
        int mid;
        
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            
            if(nums[mid]<nums[mid-1] && nums[mid]<nums[mid+1]) return nums[mid];
            else if(nums[mid]>nums[0]) lo=mid+1;
            else hi=mid-1;
        }
        return min(nums[0],nums.back());
    }
};