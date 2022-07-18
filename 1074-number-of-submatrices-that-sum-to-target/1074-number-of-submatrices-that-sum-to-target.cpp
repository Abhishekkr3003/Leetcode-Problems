class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        
        vector<vector<int>>t(n+1, vector<int>(m+1,0));
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                t[i][j]=t[i][j-1]+matrix[i-1][j-1];
            }
        }
        int res=0;
        for(int i=1;i<=n;i++){
            vector<int>temp(m+1,0);
            for(int k=i;k<=n;k++){
                unordered_map<int,int>mp;
                mp[0]=1;
                for(int j=1;j<=m;j++){
                    temp[j]+=t[k][j];
                    res+=mp[temp[j]-target];
                    mp[temp[j]]++;
                    // cout<<temp[j]<<endl;
                }
                // cout<<"res: "<<res<<endl;
            }
            
        }
        return res;
    }
};