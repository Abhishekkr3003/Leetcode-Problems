class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int maxi=*max_element(nums.begin(),nums.end());
        vector<int>prefixFreq(maxi+1);
        sort(nums.begin(),nums.end());
        int i=0;
        while(i<nums.size() && nums[i]==0) i++;
        int zeros=i;
        for(;i<nums.size();i++){
            prefixFreq[nums[i]]++;
        }
        // cout<<"hre";
        for(int i=1;i<prefixFreq.size();i++) prefixFreq[i]+=prefixFreq[i-1];
        int res=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) continue;
            for(int j=i+1;j<nums.size();j++){
                res+=prefixFreq[min(maxi,nums[i]+nums[j]-1)]-j-1+zeros;
            }
        }
        
        return res;
    }
};