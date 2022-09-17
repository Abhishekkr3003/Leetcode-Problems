class Solution {
    vector<vector<int>>t;
    
    int solve(vector<int>& nums, vector<int>& multipliers, int i, int j, int m, int n){
        int mCount=i+j;
        
        if(mCount==m) return 0;
        
        if(t[i][j]!=INT_MAX) return t[i][j];
        
        t[i][j]=max(nums[i]*multipliers[mCount]+solve(nums,multipliers,i+1,j,m,n), nums[n-j-1]*multipliers[mCount]+solve(nums,multipliers,i,j+1,m,n));
        
        // cout<<i<<" "<<j<<" "<<mCount<<" "<<t[i][j]<<endl;
        return t[i][j];
    }
    
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int m=multipliers.size();  
        int n=nums.size();
        t.resize(m+1, vector<int>(m+1,INT_MAX));

        return solve(nums,multipliers,0,0,m,n);
    }
};