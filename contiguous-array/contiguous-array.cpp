class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int res=0;
        unordered_map<int,int>mp;
        int prefix=0;
        mp[0]=0;
        for(int i=0;i<nums.size();i++){
            prefix+=(nums[i]==0)?-1:1;
            if(mp.find(prefix)!=mp.end()) res=max(res,i+1-mp[prefix]);
            else mp[prefix]=i+1;
        }
        return res;
    }
};