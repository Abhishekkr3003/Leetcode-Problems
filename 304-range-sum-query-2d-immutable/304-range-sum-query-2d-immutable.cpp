class NumMatrix {
    vector<vector<int>>prefix;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        
        prefix.resize(n,vector<int>(m));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 && j==0) prefix[i][j]=matrix[i][j];
                else if(i==0) prefix[i][j]+=prefix[i][j-1]+matrix[i][j];
                else if(j==0) prefix[i][j]+=prefix[i-1][j]+matrix[i][j];
                else prefix[i][j]=prefix[i-1][j]+prefix[i][j-1]-prefix[i-1][j-1]+matrix[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if(row1==0 && col1==0) return prefix[row2][col2];
        else if(row1==0) return prefix[row2][col2]-prefix[row2][col1-1];
        else if(col1==0) return prefix[row2][col2]-prefix[row1-1][col2];
        return prefix[row2][col2]-prefix[row1-1][col2]-prefix[row2][col1-1]+prefix[row1-1][col1-1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */