class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int lo=0, hi=nums.size()-1;
        int mid=0, ans=hi+1;
        while(lo<=hi){
            mid=lo+((hi-lo)>>1);
            if(nums[mid]==target) return mid;
            else if(nums[mid]>target){
                ans=mid;
                hi=mid-1;
            }else{
                lo=mid+1;
            }
        }
        return ans;
    }
};