class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int,int>t;
        t[0]++;
        int count=0,res=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]&1) count++;
            t[count]++;
            res+=t[count-k];
        }
        return res;
    }
};