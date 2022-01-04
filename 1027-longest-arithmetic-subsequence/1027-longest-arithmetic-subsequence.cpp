class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        vector<unordered_map<int,int>>t(nums.size());
        int res=0;
        int diff;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<i;j++){
                diff=nums[i]-nums[j];
                if(t[j].find(diff)!=t[j].end()) t[i][diff]=1+t[j][diff];
                else t[i][diff]=1;
                res=max(res,t[i][diff]);
            }
        }
        t.clear();
        return res+1;
    }
};