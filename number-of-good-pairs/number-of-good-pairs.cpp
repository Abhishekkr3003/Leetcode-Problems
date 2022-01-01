class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int>mp;
        int res=0;
        for(int i=0;i<nums.size();i++) {
            res+=mp[nums[i]];
            mp[nums[i]]++;
        }
        return res;
    }
};