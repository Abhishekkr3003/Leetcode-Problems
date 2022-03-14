class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo=0, hi=nums.size()-1;
        int mid;
        if(nums[0]==target) return 0;
        if(nums.back()==target) return nums.size()-1;
        while(lo<hi){
            mid=lo+(hi-lo)/2;
            int num=nums[mid];
            if(num<=nums[0] && target>=nums[0]) num=INT_MAX;
            else if(num>=nums[0] && target<=nums[0]) num=INT_MIN;
            
            if(num==target) return mid;
            else if(num>target) hi=mid;
            else lo=mid+1;
        }
        if(nums[lo]==target) return lo;
        return -1;
    }
};