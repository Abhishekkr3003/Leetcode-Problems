class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> ngl(n), ngr(n);
        int prevMax=0;
        for(int i=0;i<n;i++){
            ngl[i]=prevMax;
            prevMax=max(prevMax,height[i]);
        }
        prevMax=0;
        for(int i=n-1;i>=0;i--){
            ngr[i]=prevMax;
            prevMax=max(prevMax,height[i]);
        }
        
        int res=0;
        for(int i=0;i<n;i++){
            // cout<<ngr[i]<<" "<<ngl[i]<<endl;
            res+=max(0,min(ngl[i],ngr[i])-height[i]);
            // cout<<res<<endl;
        }
        return res;
    }
};