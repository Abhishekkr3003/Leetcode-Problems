class Solution {
    
    vector<vector<int>>res;
    
    void solve(unordered_map<int,int>&mp, unordered_map<int,int>::iterator it, vector<int>&cur){
        if(it==mp.end()) {
            res.push_back(cur);
            return;
        }
        solve(mp,next(it),cur);
        for(int i=0;i<it->second;i++){
            cur.push_back(it->first);
            solve(mp,next(it),cur);
        }
        for(int i=0;i<it->second;i++){
            cur.pop_back();
        }
    }
    
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        vector<int>cur;
        solve(mp,mp.begin(),cur);
        return res;
        
    }
};