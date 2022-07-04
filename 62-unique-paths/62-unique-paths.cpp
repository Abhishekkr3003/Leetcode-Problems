class Solution {
public:
    int uniquePaths(int m, int n) {
        m--;
        n--;
        
        long long res=1;
        
        int N=m+n;
        int k=min(m,n);
        int K=k;
        for(int i=0;i<k;i++){
            res*=N;
            res/=(i+1);
            N--, K--;
        }
        return res;
        
    }
};