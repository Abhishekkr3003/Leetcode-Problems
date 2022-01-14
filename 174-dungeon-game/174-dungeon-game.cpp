class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& A) {
        int m=A.size();
        int n=A[0].size();
        vector<vector<int>>t(m,vector<int>(n));
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(i==m-1 && j==n-1) t[i][j]=max(0,-A[i][j]);
                else if(i==m-1) t[i][j]=max(0,t[i][j+1]-A[i][j]);
                else if(j==n-1) t[i][j]=max(0,t[i+1][j]-A[i][j]);
                else t[i][j]=max(0, min(t[i+1][j],t[i][j+1])-A[i][j]);
            }
        }
        return 1+t[0][0];        
    }
};