class Solution {
    int atmost(vector<int>&t, int k){
        int lo=0;
        int res=0;
        unordered_map<int,int>mp;
        for(int i=0;i<t.size();i++){
            mp[t[i]]++;
            if(mp[t[i]]==1) k--;
            if(k<0){
                while(1){
                    mp[t[lo]]--;
                    if(mp[t[lo]]==0){
                        lo++;
                        break;
                    }
                    lo++;
                }
                k++;
            }
            // cout<<i<<"  -  "<<lo<<endl;
            if(k>=0) {
                res+=(i-lo+1);
                // cout<<res<<endl;
            }
        }
        // cout<<k<<" "<<res<<endl;
        return res;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmost(nums,k)-atmost(nums,k-1);
    }
}; 