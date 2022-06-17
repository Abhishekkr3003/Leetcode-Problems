class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int lo=0, hi=arr.size()-1;
        int mid=0,ans=-1;
        while(lo<=hi){
            mid=lo+(hi-lo)/2;
            
            if(arr[mid]-mid-1<k){
                ans=mid;
                lo=mid+1;
            }else hi=mid-1;
        }
        
        return (ans==-1?k:arr[ans]+(k-(arr[ans]-ans-1)));
        
    }
};