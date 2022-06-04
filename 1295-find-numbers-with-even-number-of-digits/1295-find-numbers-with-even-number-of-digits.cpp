class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int res=0;
        for(int i=0;i<nums.size();i++){
            int cur=nums[i];
            int count=0;
            while(cur){
                cur/=10;
                count++;
            }
            if((count&1)==0) res++;
        }
        return res;
    }
};