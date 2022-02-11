class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int res=0;
        int oneCount=0;
        int n=nums.size();
        for(int i=0;i<32;i++){
            oneCount=0;
            for(int num:nums){
                if((num>>i)&1) oneCount++;
            }
            res+=(n-oneCount)*oneCount;
        }
        return res;
    }
};