class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int>t(10001,0);
        int maxNum=0;
        for(int i=0;i<nums.size();i++){
            t[nums[i]]++;
            maxNum=max(maxNum,nums[i]);
        }
        t[1]=1*t[1];
        t[2]=2*t[2];
        int res=max(t[1],t[2]);
        for(int i=3;i<=maxNum;i++){
            t[i]=i*t[i]+max(t[i-2],t[i-3]);
            res=max(res,t[i]);
        }
        return res;
    }
};