class Solution {
    vector<vector<int>>res;
    void recur(int k, int n, int num, vector<int>&cur){
        if(k==0){
            if(n==0) res.push_back(cur);
            return;
        }
        if(n<=0) return;
        for(int i=num;i>=1;i--){
            cur.push_back(i);
            recur(k-1,n-i,i-1,cur);
            cur.pop_back();
        }
        return;
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>cur;
        recur(k,n,9,cur);
        return res;
    }
};