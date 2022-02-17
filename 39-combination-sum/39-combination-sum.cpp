class Solution {
    void dfs(vector<vector<int>>&res, vector<int>&cur, vector<int>&cand, int target, int pos){
        if(target==0) 
        {
            res.push_back(cur);
            return;
        }
        if(pos<0) return;
        dfs(res,cur,cand,target,pos-1);
        if(cand[pos]<=target) {
            cur.push_back(cand[pos]);
            target-=cand[pos];
            dfs(res,cur,cand,target,pos);
            cur.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>res;
        vector<int>cur;
        dfs(res,cur,candidates,target,candidates.size()-1);
        return res;
    }
};