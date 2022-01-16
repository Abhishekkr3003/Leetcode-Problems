class Solution {
    bool possible(vector<int>&b, int n, long long mid){
        long long totalToConsume=(long long)n*mid;
        for(auto a:b){
            if(a>mid) totalToConsume-=mid;
            else totalToConsume-=a;
        }
        return totalToConsume<=0;
    }
public:
    long long maxRunTime(int n, vector<int>& b) {
        long long lo=0, hi=accumulate(b.begin(),b.end(),(long long)0)/n+1;
        long long mid=0, ans=0;
        while(lo<=hi){
            mid=lo+((hi-lo)>>1);
            if(possible(b,n,mid)){
                ans=mid;
                lo=mid+1;
            }else{
                hi=mid-1;
            }
        }
        return ans;        
    }
};