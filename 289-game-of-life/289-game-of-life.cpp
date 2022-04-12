class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<pair<int,int>>moves={{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int count=0;
                for(auto move:moves){
                    if(i+move.first<n && j+move.second<m && i+move.first>=0 && j+move.second>=0){
                        if(board[i+move.first][j+move.second]&1) count++;
                    }
                }
                if(board[i][j]&1){ if(count==2 || count==3) board[i][j]=board[i][j]|2; }
                else if(count==3) board[i][j]=board[i][j]|2;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0; j<m;j++) board[i][j]=(board[i][j]>>1);                
        }
    }
};