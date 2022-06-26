class Solution {
    
    vector<pair<int,int>>moves={{0,1},{0,-1},{-1,0},{1,0}};
    
    bool dfs(vector<vector<int>>&grid, int i, int j){
        if(i<0 || j<0 || j>=grid[0].size() || i>=grid.size()) return false;
        if(grid[i][j]==1 || grid[i][j]==-1) return true;
        bool res=true;
        grid[i][j]=-1;
        for(auto move:moves){
            res=dfs(grid,i+move.first,j+move.second)&&res;
        }
        return res;
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        int res=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==0)
                    res+=dfs(grid,i,j);
            }
        }
        return res;
    }
};