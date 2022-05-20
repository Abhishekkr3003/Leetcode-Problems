class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& g) {
        int m=g.size();
        int n=g[0].size();
        vector<vector<int>>t(m,vector<int>(n,0));
        for(int i=0;i<n;i++){
            if(g[0][i]) break;
            t[0][i]=1;
        }
        for(int i=0;i<m;i++){
            if(g[i][0]) break;
            t[i][0]=1;
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(g[i][j]) continue;
                t[i][j]=t[i-1][j]+t[i][j-1];
            }
        }
        return t[m-1][n-1];
        
    }
};