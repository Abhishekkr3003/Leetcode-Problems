class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo=0, hi=nums.size()-1;
        int mid=0;
        
        
        while(lo<=hi){
            // cout<<lo<<" "<<hi<<endl;
            mid=lo+(hi-lo)/2;
            
            int curNum=nums[mid];
            if(curNum==target) return mid;
            if(nums[lo]==target) return lo;
            if(nums[hi]==target) return hi;
        
            
            if(target>nums[0] && curNum<nums[0]) curNum=INT_MAX;
            else if(target<nums[0] && curNum>nums[0]) curNum=INT_MIN;
            
            // cout<<curNum<<endl;
            if(curNum<target) lo=mid+1;
            else hi=mid-1;
        }
        return -1;
    }
};