class Solution {
    vector<int>nums;
    int justGreater(int lo, int hi, int target){
        int mid=0, ans=hi;
        while(lo<=hi){
            mid=lo+((hi-lo)>>1);
            if(nums[mid]>target){
                ans=mid;
                lo=mid+1;
            }else{
                hi=mid-1;
            }
        }
        return ans;
    }
    
    
public:
    void nextPermutation(vector<int>& nums) {
        this->nums=nums;
        int i=nums.size()-2;
        while(i>=0 && nums[i]>=nums[i+1]) i--;
        if(i<0){
            reverse(nums.begin(), nums.end());
            return;
        }
        int indexGreater=justGreater(i+1, nums.size()-1, nums[i]);
        swap(nums[i], nums[indexGreater]);
        reverse(nums.begin()+i+1,nums.end());
    }
};