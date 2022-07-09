class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        deque<pair<int,int>>q;
        q.push_back({nums[0],0});
        int curMax=nums[0];
        
        for(int i=1;i<nums.size();i++){
            curMax=nums[i]+q.front().first;
            while(!q.empty() && q.back().first<=curMax) q.pop_back();
            while(!q.empty() && q.front().second<=i-k) q.pop_front();
            q.push_back({curMax,i});
        }
        return curMax;        
    }
};