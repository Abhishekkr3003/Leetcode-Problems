class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        
        for(int i=0;i<n;i++){
            vector<int>temp;
            int r=i, c=0;
            while(r<n && c<m){
                temp.push_back(mat[r++][c++]);
            }
            sort(temp.begin(),temp.end());
            
            r=i, c=0;
            for(int j=0;j<temp.size();j++){
                mat[r++][c++]=temp[j];
            }
        }
        for(int i=1;i<m;i++){
            vector<int>temp;
            int r=0, c=i;
            while(r<n && c<m){
                temp.push_back(mat[r++][c++]);
            }
            sort(temp.begin(),temp.end());
            
            r=0, c=i;
            for(int j=0;j<temp.size();j++){
                mat[r++][c++]=temp[j];
            }
        }
        return mat;
    }
};