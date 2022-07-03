class Solution {
    
    int solve(int lo, int hi, vector<int>&s, int k, vector<vector<int>>&t){
        // cout<<lo<<" "<<hi<<endl;
        if(hi-lo+1==k) return s[hi]-s[lo-1];
        if(hi-lo+1<k) return 0;
        if(t[lo][hi]!=-1) return t[lo][hi];
        
        int res=INT_MAX;
        
        for(int i=lo;i<hi;i+=k-1){
            res=min(res,solve(lo,i,s,k,t)+solve(i+1,hi,s,k,t));
        }
        int n=(hi-lo+1);
        if(((n-1)%(k-1))==0) res+=s[hi]-s[lo-1];
        return t[lo][hi]=res;
    }
    
public:
    int mergeStones(vector<int>& stones, int k) {
        int n=stones.size();
        
        if(((n-1)%(k-1))!=0) return -1;
        
        vector<int>s(n+1,0);
        
        for(int i=0;i<n;i++){
            s[i+1]=stones[i]+s[i];
        }
       
        vector<vector<int>>t(n+1, vector<int>(n+1,-1));
        int res= solve(1,n,s,k,t);
        
        // for(auto num:t){
        //     for(int temp:num) cout<<temp<<" ";
        //     cout<<endl;
        // }
        return res;
    }
};