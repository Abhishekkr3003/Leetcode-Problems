class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int lo=0;
        int n=nums.size();
        int hi=0;
        int res=0;
        // while(hi<n && nums[hi]==1) hi++;
        // while(hi<n && nums[hi]==0 && k>0){
        //     hi++;
        //     k--;
        // }
        // res=max(res,hi-lo);
        // cout<<res<<endl;
        while(hi<n){
            if(k<0){
                if(nums[lo]==0) k++;
                lo++;
            }
            else if(hi<n && nums[hi]==1) {
                hi++;
                res=max(res,hi-lo);
            }else if(k>0){
                hi++;
                k--;
                res=max(res,hi-lo);
            }
            else{
                if(nums[lo]==0) k++;
                lo++;
                if(nums[hi]==0) k--;
                hi++;
                res=max(res,hi-lo);
            }
            // cout<<lo<<" "<<hi<<" "<<res<<" "<<hi-lo+k<<endl;            
        }
        return res;
        
    }
};