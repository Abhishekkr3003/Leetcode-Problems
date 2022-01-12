class Solution {
    
    void dfs(int n, int k, int cur, vector<int>&ans, vector<vector<int>>&res){
        if(ans.size()==k) {res.push_back(ans); return;}
        if(cur>n) return;
        for(int i=cur;i<=n;i++){
            ans.push_back(i);
            dfs(n,k,i+1,ans,res);
            ans.pop_back();
        }
    }
    
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int>cur;
        vector<vector<int>>res;
        dfs(n,k,1,cur,res);
        return res;
    }
};