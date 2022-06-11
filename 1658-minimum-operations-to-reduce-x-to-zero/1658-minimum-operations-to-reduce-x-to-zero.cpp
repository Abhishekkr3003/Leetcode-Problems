class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        unordered_map<int,int>suffix;
        suffix[0]=nums.size();
        int suf=0;
        
        for(int i=nums.size()-1;i>=0;i--){
            suf+=nums[i];
            suffix[suf]=i;
        }
        
        int res=INT_MAX;
        
        int pref=0;
        for(int i=0;i<nums.size();i++){
            auto it=suffix.find(x-pref);
            if(it!=suffix.end() && it->second>=i){
                res=min(res,i+(int)nums.size()-suffix[x-pref]);
            }
            pref+=nums[i];
        }
        return res==INT_MAX?-1:res;        
    }
};