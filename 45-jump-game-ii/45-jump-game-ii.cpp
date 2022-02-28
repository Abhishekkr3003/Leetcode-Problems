class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int>t(nums.size(),INT_MAX);
        t[0]=0;
        for(int i=0;i<nums.size();i++){
            int thresh=std::min(i+nums[i]+1, (int)nums.size());
            for(int j=i+1;j<thresh;j++){
                t[j]=min(t[j],t[i]+1);
            }
        }
        return t[nums.size()-1];
    }
};