class Solution {
public:
    int maxArea(int h, int w, vector<int>& hc, vector<int>& vc) {
        sort(hc.begin(),hc.end());
        sort(vc.begin(),vc.end());
        
        int mxHc=hc[0]-0;
        for(int i=1;i<hc.size();i++){
            mxHc=max(mxHc,hc[i]-hc[i-1]);
        }
        mxHc=max(mxHc,h-hc.back());
        
        int mxVc=vc[0]-0;
        for(int i=1;i<vc.size();i++){
            mxVc=max(mxVc,vc[i]-vc[i-1]);
        }
        mxVc=max(mxVc,w-vc.back());
        
        return ((long long)mxVc*mxHc)%(int)(1e9+7);
    }
};