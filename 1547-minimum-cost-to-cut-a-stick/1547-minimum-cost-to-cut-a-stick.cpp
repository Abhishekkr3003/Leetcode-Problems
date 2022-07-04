class Solution {
    vector<vector<int>>t;
    
    int solve(int lo, int hi, vector<int>&pcs){
        if(lo==hi) return 0;
        if(t[lo][hi]!=-1) return t[lo][hi];
        
        int res=INT_MAX;
        
        for(int i=lo;i<hi;i++){
            res=min(res,solve(lo,i,pcs)+solve(i+1,hi,pcs)+pcs[hi]-pcs[lo-1]);
        }
        return t[lo][hi]=res;
    }
    
public:
    int minCost(int n, vector<int>& cuts) {
        int cSize=cuts.size();
        sort(cuts.begin(),cuts.end());
        
        vector<int>pcs(cSize+2);
        int pSize=pcs.size();
        
        t.resize(pSize, vector<int>(pSize,-1));
        
        pcs[0]=0;
        pcs[1]=cuts[0];
        for(int i=2;i<pSize-1;i++){
            pcs[i]=pcs[i-1]+cuts[i-1]-cuts[i-2];
        }
        pcs[pSize-1]=pcs[pSize-2]+n-cuts.back();
        
        return solve(1,pSize-1,pcs);
    }
};