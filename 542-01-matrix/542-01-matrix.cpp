class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int,int>>q;
        int m=mat.size();
        int n=mat[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0) q.push({i,j});
            }
        }
        vector<pair<int,int>>moves={{0,1},{0,-1},{-1,0},{1,0}};
        int dist=0;
        while(!q.empty()){
            dist--;
            int size=q.size();
            for(int i=0;i<size;i++){
                auto cur=q.front();
                q.pop();
                for(auto move:moves){
                    if(move.first+cur.first>=0 && cur.first+move.first<m && cur.second+move.second>=0 && cur.second+move.second<n && mat[move.first+cur.first][cur.second+move.second]==1){
                        mat[move.first+cur.first][cur.second+move.second]=dist;
                        q.push({move.first+cur.first,cur.second+move.second});
                    }
                } 
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]!=0) mat[i][j]=-mat[i][j];
            }
        }
        return mat;
    }
};