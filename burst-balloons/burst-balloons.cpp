class Solution {
    vector<vector<int>>t;
    vector<int>nums;
    
    int solve(int i, int j){
        // cout<<i<<" "<<j<<endl;
        if(i-j+1==2) return 1;
        if(j-i+1==3) return nums[i]*nums[i+1]*nums[i+2];
        if(t[i][j]!=-1) return t[i][j];
        int res=0;
        for(int k=i+1;k<=j-1;k++){
            // cout<<k<<endl;
            res=max(solve(i,k)+nums[i]*nums[k]*nums[j]+solve(k,j),res);
        }
        return t[i][j]=res;
    }
    
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        t.resize(nums.size(),vector<int>(nums.size(),-1));
        this->nums=nums;
        return solve(0,nums.size()-1);
    }
};