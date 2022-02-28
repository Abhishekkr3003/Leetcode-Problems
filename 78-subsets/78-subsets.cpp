class Solution {
    vector<vector<int>>res;
    vector<int>nums;
    void recur(vector<int>&cur, int idx){
        if(idx==nums.size()) { res.push_back(cur); return; }
        recur(cur,idx+1);
        cur.push_back(nums[idx]);
        recur(cur,idx+1);
        cur.pop_back();
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        this->nums=nums;
        vector<int>cur;
        recur(cur,0);
        return res;
    }
};