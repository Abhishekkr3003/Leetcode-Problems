class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool rowZero=false, colZero=false;
        int n=matrix.size(), m=matrix[0].size();
        for(int i=0;i<n;i++) colZero=colZero||(!matrix[i][0]);
        for(int i=0;i<m;i++) rowZero=rowZero||(!matrix[0][i]);
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(!matrix[i][j]){
                    matrix[0][j]=0;
                    matrix[i][0]=0;
                }
            }
        }
        for(int i=1;i<n;i++){
            if(!matrix[i][0]) {
                for(int j=1;j<m;j++){
                    matrix[i][j]=0;
                }
            }
        }
        for(int i=1;i<m;i++){
            if(!matrix[0][i]) {
                for(int j=1;j<n;j++){
                    matrix[j][i]=0;
                }
            }
        }
        if(rowZero){
            for(int i=0;i<m;i++) matrix[0][i]=0;
        }
        if(colZero){
            for(int i=0;i<n;i++) matrix[i][0]=0;
        }
        
    }
};