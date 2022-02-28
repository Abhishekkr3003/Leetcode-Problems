class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string>res;
        if(nums.size()==0) return res;
        int count=1;
        res.push_back(to_string(nums[0]));
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]+1) {
                count++;
            }
            else{
                if(count>1) res.back()+="->"+to_string(nums[i-1]);
                res.push_back(to_string(nums[i]));
                count=1;
            }
        }
        if(count>1) res.back()+="->"+to_string(nums.back());
        return res;
    }
};