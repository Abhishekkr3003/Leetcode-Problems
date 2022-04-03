class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int num:nums) mp[num]++;
        vector<pair<int,int>>t;
        for(auto p:mp) t.push_back(p);
        sort(t.begin(),t.end(), [](pair<int,int> a, pair<int,int>b){
           if(a.second==b.second) return a.first>b.first;
            return a.second<b.second;
        });
        vector<int>res;
        for(auto p:t){
            for(int i=0;i<p.second;i++) res.push_back(p.first);
        }
        return res;
    }
};