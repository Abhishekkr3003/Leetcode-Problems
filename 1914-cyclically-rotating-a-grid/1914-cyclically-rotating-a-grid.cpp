class Solution {
    void rotate(vector<int>&t, int k){
        int lo=0, hi=k-1;
        while(lo<hi) swap(t[lo++], t[hi--]);
        lo=k, hi=t.size()-1;
        while(lo<hi) swap(t[lo++], t[hi--]);
        lo=0, hi=t.size()-1;
        while(lo<hi) swap(t[lo++], t[hi--]);
    }
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        vector<int>t;
        int m=grid.size(), n=grid[0].size();
        
        for(int i=0;m>0 && n>0;i++){
            
            int index=0;
            t.clear();
            t.resize(m*n-(max(m-2,0)*max(n-2,0)));
            // cout<<m<<" "<<n<<endl;
            for(int j=i;j<grid[0].size()-i;j++){
                t[index++]=grid[i][j];
            }
            for(int j=i+1;j<grid.size()-i;j++){
                t[index++]=grid[j][grid[0].size()-1-i];
            }
            if(i!=grid[0].size()-i-1){
                for(int j=grid[0].size()-2-i;j>=i;j--){
                    t[index++]=grid[grid.size()-1-i][j];
                }
            }
            // cout<<index<<endl;
            if(i!=grid.size()-i-1){
                for(int j=grid.size()-i-2;j>i;j--){
                    t[index++]=grid[j][i];
                }
            }
            
//             cout<<"here"<<endl;
            
//             for(int num:t) cout<<num<<" ";
//             cout<<endl;
            
            rotate(t,k%t.size());
            
            // for(int num:t) cout<<num<<" ";
            // cout<<endl;
            
            index=0;
            for(int j=i;j<grid[0].size()-i;j++){
                grid[i][j]=t[index++];
            }
            for(int j=i+1;j<grid.size()-i;j++){
                grid[j][grid[0].size()-1-i]=t[index++];
            }
            if(i!=grid[0].size()-i-1){
                for(int j=grid[0].size()-2-i;j>=i;j--){
                    grid[grid.size()-1-i][j]=t[index++];
                }
            }
            if(i!=grid.size()-i-1){
                for(int j=grid.size()-i-2;j>i;j--){
                    grid[j][i]=t[index++];
                }
            }
            m-=2, n-=2;
            // for(auto v:grid){
            //     for(int num:v) cout<<num<<" ";
            //     cout<<endl;
            // }
        }
        return grid;
    }
};