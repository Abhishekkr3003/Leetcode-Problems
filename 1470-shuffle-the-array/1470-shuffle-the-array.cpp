class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        for(int i=0;i<n;i++){
            int num;
            if(nums[i]>1000) num=nums[i]/1001;
            else num=nums[i];
            nums[i+i]=nums[i+i]*1001+num;
        }
        
        
        int j=n;
        for(int i=1;i<nums.size();i+=2){
            int num;
            if(nums[j]>1000) num=nums[j]/1001;
            else num=nums[j];
            nums[i]=nums[i]*1001+num;
            j++;
        }
        
        for(int i=0;i<nums.size();i++) nums[i]=nums[i]%1001;
        return nums;
        
    }
};