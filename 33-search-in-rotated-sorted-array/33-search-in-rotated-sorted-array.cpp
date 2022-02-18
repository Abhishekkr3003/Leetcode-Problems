class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo=0, hi=nums.size()-1;
        if(nums[0]==target) return 0;
        int mid,num;
        while(lo<=hi){
            if(lo==hi-1){
                if(nums[lo]==target) return lo;
                else if(nums[hi]==target) return hi;
            }
            mid=lo+((hi-lo)>>1);
            if(nums[mid]>nums[0] && target<nums[0]) num=INT_MIN;
            else if(nums[mid]<nums[0] && target>nums[0]) num=INT_MAX;
            else num=nums[mid];
            
            if(num==target) return mid;
            else if(num<target) lo=mid+1;
            else hi=mid-1;
        }
        return -1;        
    }
};