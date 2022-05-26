class Solution {
    vector<vector<int>> t;
    int n;
    int solve(int f, int e) {
        if (f == 0) return 0;
        if (e == 1) return f;
        if (t[f][e] != -1) return t[f][e];
        int res = n + 1;
        int lo=1, hi=f;
        int mid=0, t1=0, t2=0;
        while(lo<=hi){
            mid=lo+(hi-lo)/2;
            t1=solve(mid-1,e-1);
            t2=solve(f-mid,e);
            if(t1<t2){
                lo=mid+1;
            }else if(t2<t1){
                hi=mid-1;
            }else{
                res=min(res,1+max(t1,t2));   
                break;
            }
            res=min(res,1+max(t1,t2));     
        }
        // for (int k = 1; k <= f; k++) {
        //     res = min(res, 1 + max(solve(k - 1, e - 1), solve(f - k, e)));
        // }
        return t[f][e] = res;
    }

public:
    int superEggDrop(int k, int n) {
        t.resize(n + 1, vector<int>(k + 1, -1));
        this->n = n;
        return solve(n, k);
    }
};