class Solution {
    vector<vector<int>>res;
    
    void recur(vector<int>&cur, int k, int n, int num){
        if(k==0){
            if(n==0) res.push_back(cur);
            return;
        } 
        if(n<=0 || num<=0) return;
        recur(cur,k,n,num-1);
        cur.push_back(num);
        recur(cur,k-1,n-num,num-1);
        cur.pop_back();
    }
    
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>cur;
        recur(cur,k,n,9);
        return res;
    }
};