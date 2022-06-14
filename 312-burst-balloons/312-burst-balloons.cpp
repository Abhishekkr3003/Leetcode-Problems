class Solution {
    
    vector<vector<int>>t;
    
    int solve(vector<int>&arr, int lo, int hi){
        if(lo>hi) return 0;
        if(lo==hi) return arr[lo-1]*arr[lo]*arr[hi+1];
        if(t[lo][hi]!=-1) return t[lo][hi];
        
        for(int i=lo;i<=hi;i++){
            t[lo][hi]=max(t[lo][hi], arr[lo-1]*arr[i]*arr[hi+1]+solve(arr,lo,i-1)+solve(arr,i+1,hi));
        }
        return t[lo][hi];
    }
    
    
public:
    int maxCoins(vector<int>& nums) {
        vector<int>arr(nums.size()+2);
        
        arr[0]=1;
        for(int i=0;i<nums.size();i++){
            arr[i+1]=nums[i];
        }
        arr[nums.size()+1]=1;
        
        t.resize(arr.size(), vector<int>(arr.size(),-1));
        return solve(arr,1,arr.size()-2);
        
    }
};