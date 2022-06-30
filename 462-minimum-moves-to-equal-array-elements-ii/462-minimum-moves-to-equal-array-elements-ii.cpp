class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int mid=nums[nums.size()/2];
        
        int res=0;
        for(int &num:nums){
            res+=abs(num-mid);
        }
        
        return res;
    }
};