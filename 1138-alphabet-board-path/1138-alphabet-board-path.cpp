class Solution {
    int n=6, m=5;
    
    string bfs(vector<string>&grid, char src, char dest){
        
        queue<pair<int, string>>q;
            
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(src==grid[i][j]){
                    q.push({i*m+j,""});
                    break;
                }
            }
            if(!q.empty()) break;
        }
        vector<int>vis(26,0);
        
        while(!q.empty()){
            int x=(q.front().first)/m;
            int y=(q.front().first)%m;
            string curStr=q.front().second;
            q.pop();
            // cout<<curStr<<endl;
            
            if(dest==grid[x][y]) return curStr;
            
            // cout<<"here1"<<endl;
            if(x>0 && !vis[(x-1)*m+y]){
                q.push({(x-1)*m+y,curStr+"U"});
                vis[(x-1)*m+y]=true;
            }
            // cout<<"here2"<<endl;
            if(y>0 && !vis[x*m+y-1]){
                q.push({x*m+y-1,curStr+"L"});
                vis[x*m+y-1]=true;
            }
            // cout<<"here3"<<endl;
            if(((x<n-2)||(x==n-2 && y==0)) && !vis[(x+1)*m+y]){
                q.push({(x+1)*m+y,curStr+"D"});
                vis[(x+1)*m+y]=true;
            }
            // cout<<"here4"<<endl;
            if((y<m-1 && x<n-1) && !vis[x*m+y+1]){
                q.push({x*m+y+1,curStr+"R"});
                vis[x*m+y+1]=true;
            }
            // cout<<"here5"<<endl;
        }
        return "";       
        
    }
    
public:
    string alphabetBoardPath(string target) {
        vector<string>grid={"abcde", "fghij", "klmno", "pqrst", "uvwxy", "z"};
        
        char src='a', dest=target[0];
        string res=bfs(grid,src,dest)+"!";
        // cout<<"here";
        // cout<<res<<endl;
        
        for(int i=1;i<target.length();i++){
            src=dest;
            dest=target[i];
            // cout<<res<<endl;
            res+=bfs(grid,src,dest)+"!";
            // cout<<res<<endl;
        }
        return res;
        
    }
};