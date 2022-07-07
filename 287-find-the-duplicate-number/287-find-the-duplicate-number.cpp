// Bit Manipulation | M | Time: O(n) | Space: O(1)

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<int>bitCount(32,0);
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<32;j++) {
                if(nums[i]&(1<<j)) bitCount[j]++;
            }
            for(int j=0;j<32;j++) {
                if((i)&(1<<j)) bitCount[j]--;
            }
        }
        int res=0;
        for(int i=0;i<32;i++){
            if(bitCount[i]>0) res+=(1<<i);
        }
        return res;
    }
};