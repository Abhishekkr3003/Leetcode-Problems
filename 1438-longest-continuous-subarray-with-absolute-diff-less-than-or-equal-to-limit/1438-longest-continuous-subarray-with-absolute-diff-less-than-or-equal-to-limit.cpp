class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n=nums.size();
        deque<int>mins, maxs;
        int res=1;
        mins.push_back(0);
        maxs.push_back(0);
        
        int start=0;
        for(int end=1;end<n;end++){
            while(!mins.empty() && nums[mins.back()]>nums[end]) mins.pop_back();
            while(!maxs.empty() && nums[maxs.back()]<nums[end]) maxs.pop_back();
            mins.push_back(end);
            maxs.push_back(end);
            while(!mins.empty() && !maxs.empty() && abs(nums[mins.front()]-nums[maxs.front()])>limit){
                if(mins.front()<maxs.front()) {
                    start=mins.front()+1;
                    mins.pop_front();
                }
                else {
                    start=maxs.front()+1;
                    maxs.pop_front(); 
                }
            }
            res=max(res,end-start+1);
        }
        return res;
    }
};