class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        int start=0, end=nums.size()-1;
        while(1){
            int i=start-1,j=start;
            int pivot=nums[end];
            while(j<end){
                if(nums[j]<pivot) swap(nums[j],nums[++i]);
                j++;
            }
            swap(nums[end],nums[++i]);
            if(i==n-k) return pivot;
            else if(i>n-k){
                end=i-1;
            }else{
                start=i+1;
            }
        }
        return -1;
    }
};