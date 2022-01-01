class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int diags=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            diags=max(diags, (int)nums[i].size()+i);
        }
        vector<vector<int>>res(diags);
        for(int i=0;i<n;i++){
            for(int j=0;j<nums[i].size();j++){
                res[i+j].push_back(nums[i][j]);
            }
        }
        vector<int>ans;
        for(auto v:res){
            for(int i=v.size()-1;i>=0;i--) ans.push_back(v[i]);   
        }
        return ans;
    }
};