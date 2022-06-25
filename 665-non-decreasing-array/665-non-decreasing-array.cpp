class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        bool modified=false;
        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i]>nums[i+1]){
                if(modified) return false;
                if(i<nums.size()-2 && nums[i]<=nums[i+2]){
                    nums[i+1]=nums[i+2];
                    modified=true;
                }else if(i==nums.size()-2){
                    nums[i+1]=nums[i];
                    modified=true;
                }
                else{
                    nums[i]=nums[i+1];
                    modified=true;
                }
            }
        }
        return true;
    }
};