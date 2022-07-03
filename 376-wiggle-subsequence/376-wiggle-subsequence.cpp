class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size()<2) return nums.size();
        
        int len=2;
        int i=1;
        while(i<nums.size() && nums[i]==nums[i-1]) i++;
        if(i==nums.size()) return 1;
        int cur=nums[i];
        int prev=nums[i-1];
        bool smaller=(cur-prev<0?false:true);
        prev=cur;
        
        for(;i<nums.size();i++){
            if(smaller){
                if(nums[i]<prev) {
                    len++;
                    prev=nums[i];
                    smaller=false;
                }else{
                    prev=nums[i];
                }
            }else{
                if(nums[i]>prev) {
                    len++;
                    prev=nums[i];
                    smaller=true;
                }else{
                    prev=nums[i];
                }
            }
        }
        return len;        
    }
};