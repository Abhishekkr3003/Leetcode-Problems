class Solution {
    int res=0;
    
    void merge(vector<int>&nums, int lo, int hi, int mid){
        vector<int>temp(hi-lo+1);
        int i=lo, j=mid+1, k=0;
        while(i<=mid && j<=hi){
            if(nums[j]<=nums[i]){
                res+=(nums.begin()+mid+1)-upper_bound(nums.begin()+lo,nums.begin()+mid+1,2ll*nums[j]);
                temp[k++]=nums[j++];
                
            }else{
                temp[k++]=nums[i++];
            }
        }
        while(i<=mid) temp[k++]=nums[i++];
        while(j<=hi) {
            res+=(nums.begin()+mid+1)-upper_bound(nums.begin()+lo,nums.begin()+mid+1,2ll*nums[j]);
            temp[k++]=nums[j++];
        }
        
        for(int i=0;i<hi-lo+1;i++){
            nums[i+lo]=temp[i];
        }
    }
    
    void dnc(vector<int>&nums, int lo, int hi){
        if(lo>=hi) return;
        int mid=lo+(hi-lo)/2;
        dnc(nums,lo,mid);
        dnc(nums,mid+1,hi);
        merge(nums,lo,hi,mid);
    }
    
public:
    int reversePairs(vector<int>& nums) {
        dnc(nums,0,nums.size()-1);
        // for(int i=0;i<nums.size();i++) cout<<nums[i]<<" ";
        return res;
    }
};