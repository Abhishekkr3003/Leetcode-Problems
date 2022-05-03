/* 
    Time: O(n)
    Space: O(1)
    Tag: Array Manipulation
    Difficulty: M
*/

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int start=0, end=0;
        int mn=nums[0], mx=nums[0];
        int i=0;
        while(i<nums.size()-1 && nums[i]<nums[i+1]) {
            mx=mn=nums[i];
            i++;
            start=end=i;
        }
        // cout<<start<<end<<endl;
        for(;i<nums.size();i++){
            if(nums[i]<mn) {
                // cout<<"here";
                mn=nums[i];
                while(start>=0 && nums[i]<nums[start]) start--;
                start++;
                end=i;
            }else if(nums[i]<mx){
                end=i;
            }else{
                mx=nums[i];
            }
        }
        // cout<<start<<end<<endl;
        return (end==start?0:end-start+1);
        
    }
};