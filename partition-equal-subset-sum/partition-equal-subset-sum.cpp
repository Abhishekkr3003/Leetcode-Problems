class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++) sum+=nums[i];
        if(sum&1) return false;
        sum/=2;
        vector<bool>t(sum+1,0);
        vector<bool>temp(sum+1);
        t[0]=1;
        for(int i=1;i<=nums.size();i++){
            temp[0]=1;
            for(int j=1;j<=sum;j++){
                temp[j]=(nums[i-1]<=j)?(t[j-nums[i-1]]||t[j]):t[j];
            }
            t=temp;
        }
        return t[sum];
    }
};