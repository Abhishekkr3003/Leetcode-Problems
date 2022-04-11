class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>res(m,vector<int>(n));
        int size=m*n;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int newLoc=(i*n+j+k)%size;
                res[newLoc/n][newLoc%n]=grid[i][j];
            }
        }
        return res;
    }
};