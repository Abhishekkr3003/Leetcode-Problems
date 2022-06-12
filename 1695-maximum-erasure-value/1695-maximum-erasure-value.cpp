class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int>st;
        int curSum=0;
        int start=0;
        int res=0;
        for(int i=0;i<nums.size();i++){
            while(st.count(nums[i])){
                curSum-=nums[start];
                st.erase(nums[start++]);
            }
            curSum+=nums[i];
            res=max(res,curSum);
            st.insert(nums[i]);
        }
        return res;
    }
};