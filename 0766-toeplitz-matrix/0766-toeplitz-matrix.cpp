class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        
        for(int i=0;i<n;i++){
            int val=matrix[i][0];
            for(int j=0;i+j<n && j<m;j++){
                if(matrix[i+j][j]!=val) return false;
            }
        }
        
        for(int i=1;i<m;i++){
            int val=matrix[0][i];
            for(int j=0;i+j<m && j<n;j++){
                if(matrix[j][i+j]!=val) return false;
            }
        }
        
        return true;
    }
};