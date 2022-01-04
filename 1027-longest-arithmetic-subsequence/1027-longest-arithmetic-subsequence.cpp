class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        vector<vector<int>>t(nums.size(), vector<int>(1010,0));
        int res=0;
        int diff;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<i;j++){
                diff=nums[i]-nums[j];
                t[i][diff+501]=1+t[j][diff+501];
                res=max(res,t[i][diff+501]);
            }
        }
        return res+1;
    }
};