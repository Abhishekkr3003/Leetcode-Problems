class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size()-1;
        int lo=0, hi=n;
        int mid,ans=0;
        while(lo<=hi){
            mid=lo+((hi-lo)>>1);
            if(nums[mid]>nums[n]) lo=mid+1;
            else {
                ans=mid;
                hi=mid-1;
            }
        }
        return nums[ans];
    }
};