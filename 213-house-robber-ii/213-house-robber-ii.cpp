class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        if(nums.size()==2) return max(nums[0], nums[1]);
        if(nums.size()==3) return max(nums[0], max(nums[1], nums[2]));
        vector<int>t(nums.size()-1);
        t[0]=nums[0];
        t[1]=nums[1];
        t[2]=nums[0]+nums[2];
        for(int i=3;i<t.size();i++){
            t[i]=nums[i]+max(t[i-2],t[i-3]);
        }
        int res=max(t[t.size()-1],t[t.size()-2]);
        t.clear();
        t.resize(nums.size());
        t[0]=0;
        t[1]=nums[1];
        t[2]=nums[2];
        for(int i=3;i<t.size();i++){
            t[i]=nums[i]+max(t[i-2],t[i-3]);
        }
        res=max(res, max(t[t.size()-1],t[t.size()-2]));
        return res;
    }
};