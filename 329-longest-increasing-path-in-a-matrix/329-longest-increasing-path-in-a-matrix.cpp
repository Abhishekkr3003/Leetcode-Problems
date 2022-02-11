class Solution {
    vector<vector<int>>t;
    vector<vector<int>>matrix;
    
    int dfs(int i, int j){
        if(t[i][j]!=-1) return t[i][j];
        int max_=0;
        if(i>0 && matrix[i-1][j]>matrix[i][j]) max_=max(max_,dfs(i-1,j));
        if(j>0 && matrix[i][j-1]>matrix[i][j]) max_=max(max_,dfs(i,j-1));
        if(i<matrix.size()-1 && matrix[i+1][j]>matrix[i][j]) max_=max(max_,dfs(i+1,j));
        if(j<matrix[0].size()-1 && matrix[i][j+1]>matrix[i][j]) max_=max(max_,dfs(i,j+1));
        return t[i][j]=max_+1;
    }
    
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        this->matrix=matrix;
        t.resize(matrix.size(),vector<int>(matrix[0].size(),-1));
        int res=0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                res=max(res,dfs(i,j));
            }
        }
        return res;
    }
};