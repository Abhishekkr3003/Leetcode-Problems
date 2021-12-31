class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int temp;
        for(int k=0;k<n/2;k++){
            for(int i=0;i<n-(2*k)-1;i++){
                temp=matrix[k][i+k];
                matrix[k][i+k]=matrix[n-1-i-k][k];
                matrix[n-1-i-k][k]=matrix[n-1-k][n-1-i-k];
                matrix[n-1-k][n-1-i-k]=matrix[i+k][n-1-k];
                matrix[i+k][n-1-k]=temp;
            }
        }
    }
};