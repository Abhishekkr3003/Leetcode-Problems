class Solution {
    
    bool possible(vector<int>&nums, int m, int sum){
        int curSum=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>sum) return false;
            if(curSum+nums[i]>sum){
                m--;
                curSum=nums[i];
            }else{
                curSum+=nums[i];
            }
        }
        return m>0;
    }
    
public:
    int splitArray(vector<int>& nums, int m) {
        int lo=*min_element(nums.begin(),nums.end()), hi=accumulate(nums.begin(),nums.end(),0);
        int mid=0, ans=-1;
        
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(possible(nums,m,mid)){
                ans=mid;
                hi=mid-1;
            }else lo=mid+1;
        }
        return ans;
    }
};