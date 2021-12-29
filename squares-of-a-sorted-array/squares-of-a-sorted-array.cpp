class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int i=0, j=nums.size()-1;
        vector<int>res(nums.size());
        int k=nums.size()-1;
        while(i<=j){
            if(nums[i]*nums[i]>nums[j]*nums[j]) { res[k--]=nums[i]*nums[i]; i++; } 
            else { res[k--]=nums[j]*nums[j]; j--; }
        }
        return res;
    }
};