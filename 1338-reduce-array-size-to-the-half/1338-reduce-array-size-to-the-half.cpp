class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int>mp;
        for(int val:arr) mp[val]++;
        
        vector<int>vals;
        
        for(auto p:mp){
            vals.push_back(p.second);
        }
        
        sort(vals.rbegin(),vals.rend());
        
        int ans=0;
        int ptr=0;
        
        int thresh=(arr.size()+1)/2;
        
        while(thresh>0){
            thresh-=vals[ptr++];
            ans++;
        }
        return ans;
    }
};