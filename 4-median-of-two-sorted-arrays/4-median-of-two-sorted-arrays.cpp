class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        
        if(n>m) return findMedianSortedArrays(nums2,nums1);
        
        int lo=0, hi=n;
        int mid=0;
        
        while(lo<=hi){
            mid=lo+(hi-lo)/2;
            
            int x1,x2,y1,y2;
            if(mid==0) x1=INT_MIN;
            else x1=nums1[mid-1];
            if(mid==n) x2=INT_MAX;
            else x2=nums1[mid];
            
            int secBreak=((m+n)/2)-mid;
            if(secBreak==0) y1=INT_MIN;
            else y1=nums2[secBreak-1];
            if(secBreak==m) y2=INT_MAX;
            else y2=nums2[secBreak];
            
            // cout<<mid<<" "<<secBreak<<endl;
            if(x1>y2) hi=mid-1;
            else if(x2<y1) lo=mid+1;
            else {
                if((m+n)&1) return min(x2,y2);
                else return (max(x1,y1)+min(x2,y2))/2.0;
            }
        }
        return -1;
    }
};