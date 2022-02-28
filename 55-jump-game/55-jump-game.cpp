class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<bool>t(nums.size(),false);
        t[0]=true;
        for(int i=0;i<nums.size();i++){
            if(t[i]==false) return false;
            int thresh=std::min(i+nums[i]+1, (int)nums.size());
            for(int j=i+1;j<thresh;j++){
                t[j]=true;
            }
        }
        return t[nums.size()-1];
    }
};
// Can be solved in O(n) time