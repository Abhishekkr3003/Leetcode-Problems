class Solution {
public:
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        int sum1=accumulate(nums1.begin(),nums1.end(),0);
        int sum2=accumulate(nums2.begin(),nums2.end(),0);
        
        int maxSum=0, curSum=0;
        
        for(int i=0;i<nums1.size();i++){
            curSum+=nums2[i]-nums1[i];
            
            maxSum=max(maxSum,curSum);
            
            if(curSum<0) curSum=0;
        }
        
        int res=max(sum1,sum2);
        res=max(res,sum1+maxSum);
        
        maxSum=0, curSum=0;
        for(int i=0;i<nums1.size();i++){
            curSum+=nums1[i]-nums2[i];
            
            maxSum=max(maxSum,curSum);
            
            if(curSum<0) curSum=0;
        }
        
        res=max(res,sum2+maxSum);
        return res;        
    }
};