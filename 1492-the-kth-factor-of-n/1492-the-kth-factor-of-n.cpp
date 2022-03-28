class Solution {
public:
    int kthFactor(int n, int k) {
        int i=1;
        for(;i<=n && k;i++){
            if(n%i==0) k--;
        }
        if(k) return -1;
        return i-1;
    }
};