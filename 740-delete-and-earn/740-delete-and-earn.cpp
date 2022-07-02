class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int &num:nums){
            mp[num]++;
        }
        vector<pair<int,int>>v;
        for(auto p:mp) v.push_back({p.first,p.second});
        sort(v.begin(),v.end());
        
        vector<int>t(v.size()+1);
        t[0]=0;
        t[1]=v[0].first*v[0].second;
        
        for(int i=1;i<v.size();i++){
            if(v[i].first==v[i-1].first+1){
                t[i+1]=max(t[i],v[i].first*v[i].second+t[i-1]);
            }else{
                t[i+1]=t[i]+v[i].first*v[i].second;
            }
        }
        int n=v.size();
        return max(t[n],t[n-1]);
    }
};