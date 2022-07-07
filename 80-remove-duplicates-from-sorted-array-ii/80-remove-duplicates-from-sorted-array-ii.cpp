class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==1) return 1;
        int j=1;
        for(int i=2;i<nums.size();i++){
            if(nums[i]!=nums[j] || nums[i]!=nums[j-1]){
                swap(nums[++j],nums[i]);
            }
        }
        return j+1;
    }
};