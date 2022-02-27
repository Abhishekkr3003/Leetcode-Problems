class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>res;
        int si=0, ei=0, curSum=0;
        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size();i++){
            if(i>0 && nums[i]==nums[i-1])
                continue;
            si=i+1;ei=nums.size()-1;
            while(si<ei){
                curSum=nums[si]+nums[ei]+nums[i];
                if(curSum==0){
                    res.push_back({nums[si],nums[ei],nums[i]});
                    while(ei>si && nums[ei]==nums[ei-1])
                        ei--;
                    while(si<ei && nums[si]==nums[si+1])
                        si++;
                    ei--;si++;
                }
                else{
                    if(curSum>0) ei--;
                    else si++;
                }
            }
            
        }
        return res;
        
        
    }
};