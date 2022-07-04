class Solution {
    vector<vector<int>>t;
    
    int solve(vector<int>&nums1, vector<int>&nums2, int idx, bool swapped){
        if(idx==nums1.size()) return 0;
        if(t[idx][swapped]!=-1) return t[idx][swapped];
        
        int res=INT_MAX-1;
        
        if(nums1[idx]>nums1[idx-1] && nums2[idx]>nums2[idx-1]){
            res=min(res,solve(nums1,nums2,idx+1,false));
        }
        if(nums1[idx]>nums2[idx-1] && nums2[idx]>nums1[idx-1]){
            swap(nums1[idx],nums2[idx]);
            res=min(res,1+solve(nums1,nums2,idx+1,true));
            swap(nums1[idx],nums2[idx]);
        }
        return t[idx][swapped]=res;
    }
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        t.resize(nums1.size(), vector<int>(2,-1));
        int res=INT_MAX-1;
        res=min(res,solve(nums1,nums2,1,false));
        swap(nums1[0],nums2[0]);
        res=min(res,1+solve(nums1,nums2,1,true));
        return res;
    }
};