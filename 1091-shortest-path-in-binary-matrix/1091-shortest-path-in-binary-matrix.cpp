class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) 
    {
        int N=grid.size();
        queue<pair<int, int>>q;
        if(grid[0][0]) return -1;
        q.push({0,0});
        set<pair<int,int>>visited;
        pair<int, int>index;
        int count=0;
        vector<pair<int,int>>moves={{0,1},{0,-1},{-1,0},{1,0},{-1,1},{1,-1},{1,1},{-1,-1}};
        while(!q.empty()){
            int size=q.size();
            count++;
            for(int i=0;i<size;i++){
                index=q.front();
                q.pop();
                if(index.first==N-1 && index.second==N-1) return count;
                for(auto move:moves){
                    if(index.first+move.first<N && index.first+move.first>=0 && index.second+move.second<N && index.second+move.second>=0 && grid[index.first+move.first][index.second+move.second]==0 && visited.find({index.first+move.first,index.second+move.second})==visited.end()){
                        q.push({index.first+move.first,index.second+move.second});
                        visited.insert({index.first+move.first,index.second+move.second});
                    }
                }
            }
        }
        return -1;  
    }
};