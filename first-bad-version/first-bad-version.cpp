// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int lo=1, hi=n;
        int mid=0, ans=lo;
        while(lo<=hi){
            mid=lo+((hi-lo)>>1);
            if(isBadVersion(mid)){
                ans=mid;
                hi=mid-1;
            }else{
                lo=mid+1;
            }
        }
        return ans;
    }
};