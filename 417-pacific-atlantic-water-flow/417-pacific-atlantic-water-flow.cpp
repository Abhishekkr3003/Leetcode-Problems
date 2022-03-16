// Do two times BFS

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        queue<pair<int,int>>q;
        int n=heights.size();
        int m=heights[0].size();
        vector<bool>visited(n*m,false);
        vector<bool>pacific(n*m,false);
        vector<pair<int,int>>moves={{1,0},{-1,0},{0,1},{0,-1}};
        
        //Start BFS
        for(int i=0;i<m;i++) {
            if(!visited[i]){
                q.push({0,i});
                visited[i]=1;
                pacific[i]=1;
            }
        }
        for(int j=0;j<n;j++){
            if(!visited[m*j]){
                q.push({j,0});
                visited[m*j]=1;
                pacific[m*j]=1;
            }
        }
        while(!q.empty()){
            pair<int,int> pos=q.front();
            q.pop();
            for(pair<int,int> move:moves){
                if(pos.first+move.first>=0 && pos.first+move.first<n && pos.second+move.second>=0 && pos.second+move.second<m && !visited[(pos.first+move.first)*m+(pos.second+move.second)] && heights[pos.first+move.first][pos.second+move.second]>=heights[pos.first][pos.second]){
                    q.push({pos.first+move.first,pos.second+move.second});
                    visited[(pos.first+move.first)*m+(pos.second+move.second)]=1;
                    pacific[(pos.first+move.first)*m+(pos.second+move.second)]=1;
                }
            }
        }
        vector<vector<int>>res;
        visited.clear();
        visited.resize(n*m,false);
        for(int i=0;i<m;i++) {
            if(!visited[(n-1)*m+i]){
                q.push({n-1,i});
                visited[(n-1)*m+i]=1;
                if(pacific[(n-1)*m+i]) res.push_back({n-1,i});
            }
        }
        for(int j=0;j<n;j++){
            if(!visited[(m*j)+m-1]){
                q.push({j,m-1});
                visited[(m*j)+m-1]=1;
                if(pacific[(m*j)+m-1]) res.push_back({j,m-1});
            }
        }   
        while(!q.empty()){
            pair<int,int> pos=q.front();
            q.pop();
            for(pair<int,int> move:moves){
                if(pos.first+move.first>=0 && pos.first+move.first<n && pos.second+move.second>=0 && pos.second+move.second<m && !visited[(pos.first+move.first)*m+(pos.second+move.second)] && heights[pos.first+move.first][pos.second+move.second]>=heights[pos.first][pos.second]){
                    q.push({pos.first+move.first,pos.second+move.second});
                    visited[(pos.first+move.first)*m+(pos.second+move.second)]=1;
                    if(pacific[(pos.first+move.first)*m+(pos.second+move.second)]) res.push_back({pos.first+move.first,pos.second+move.second});
                }
            }
        }
        return res;
    }
};