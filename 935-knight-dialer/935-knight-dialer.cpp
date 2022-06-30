class Solution {
    vector<vector<int>>moves={{4,6},{6,8},{7,9},{4,8},{0,3,9},{},{0,1,7},{2,6},{1,3},{2,4}};
    int dfs(int n, int curNum,vector<vector<int>>&t){
        if(n==0) return 1;
        if(t[curNum][n]!=-1) return t[curNum][n];
        
        int res=0;
        int mod=1e9+7;
        for(int move:moves[curNum]){
            res=(res+dfs(n-1,move,t))%mod;
        }
        return t[curNum][n]=res;
    }
    
public:
    int knightDialer(int n) {        
        vector<vector<int>>t(10,vector<int>(n,-1));
        int res=0;
        int mod=1e9+7;
        for(int i=0;i<10;i++){
            res=(res+dfs(n-1,i,t))%mod;
        }
        return res;
    }
};