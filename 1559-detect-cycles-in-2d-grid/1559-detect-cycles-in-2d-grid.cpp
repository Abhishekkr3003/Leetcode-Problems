class Solution {
    
    vector<pair<int,int>>moves={{0,1},{0,-1},{-1,0},{1,0}};
    
    bool dfs(vector<vector<char>>& grid, int i, int j, int parX, int parY){
        char ch=grid[i][j];
        grid[i][j]='#';
        for(auto move:moves){
            if(i+move.first>=0 && i+move.first<grid.size() && j+move.second>=0 && j+move.second<grid[0].size() && !(i+move.first==parX && j+move.second==parY)){
                if(grid[i+move.first][j+move.second]=='#') return true;
                if(grid[i+move.first][j+move.second]==ch && dfs(grid,i+move.first,j+move.second,i,j)) return true;
            }
        }
        grid[i][j]='*';
        return false;
    }
    
public:
    bool containsCycle(vector<vector<char>>& grid) {
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]!='*') if(dfs(grid,i,j,-10,-10)) return true;
            }
        }
        return false;
    }
};