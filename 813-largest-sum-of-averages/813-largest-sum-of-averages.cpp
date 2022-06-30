class Solution {
    vector<vector<double>>t;
    
    double solve(vector<int>&nums, int idx, int k){
        if(idx>=nums.size()){
            if(k==-1) return 0;
            return INT_MIN;
        } 
        if(k<0) return INT_MIN;
        if(t[idx][k]!=-1) return t[idx][k];
        
        double res=0;
        int sum=0;
        for(int i=idx;i<nums.size();i++){
            sum+=nums[i];
            double temp=solve(nums,i+1,k-1);
            if(temp!=INT_MIN){
                res=max(res,(double)sum/(i-idx+1)+temp);
            }
        }
        return t[idx][k]=res;
    }
    
public:
    double largestSumOfAverages(vector<int>& nums, int k) {
        t.resize(nums.size(),vector<double>(k,-1));
        return solve(nums,0,k-1);
    }
};