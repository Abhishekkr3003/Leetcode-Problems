class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        int n=nums.size();
        
        for(int i=0;i<n;i++){
            int j=nums[i];
            while(j>0 && j<=n && nums[j-1]!=j){
                swap(j,nums[j-1]);
            }
        }
        for(int i=0;i<n;i++){
            // cout<<nums[i]<<endl;
            if(i+1!=nums[i]) return i+1;
        }
        return n+1;
    }
};