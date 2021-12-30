class Solution {
public:
    int smallestRepunitDivByK(int k) {
        unordered_set<int>visited_;
        if(k%2==0) return -1;
        int len=0;
        int curRem=0;
        while(1){
            curRem=(curRem*10+1)%k;
            len++;
            if(curRem==0) return len;
            if(visited_.find(curRem)!=visited_.end()) return -1;
            visited_.insert(curRem);
        }
        return 0;
    }
};