class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int lo=0, hi=nums.size()-1;
        int mid=0;
        
        
        while(lo<=hi){
            // cout<<lo<<" "<<hi<<endl;
            mid=lo+(hi-lo)/2;
            
            int curNum=nums[mid];
            if(curNum==target || nums[lo]==target || nums[hi]==target) return true;
     
            if(target>nums[0] && curNum<nums[0]) curNum=INT_MAX;
            else if(target<=nums[0] && curNum>=nums[0]) curNum=INT_MIN;
            
            if(nums[lo]==nums[hi]) hi--, lo++;
            else if(curNum<target) lo=mid+1;
            else hi=mid-1;
        }
        return false;
    }
};