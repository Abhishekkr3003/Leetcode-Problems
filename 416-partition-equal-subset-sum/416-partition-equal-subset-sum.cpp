class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum&1) return false;
        sum/=2;
        
        vector<bool>t(sum+1,false), nxt(sum+1);
        t[0]=true;
        
        for(int i=0;i<nums.size();i++){
            nxt[0]=true;
            for(int j=1;j<=sum;j++){
                if(nums[i]<=j){
                    nxt[j]=t[j]||t[j-nums[i]];
                }else{
                    nxt[j]=t[j];
                }
            }
            t=nxt;
        }
        return t[sum];
    }
};