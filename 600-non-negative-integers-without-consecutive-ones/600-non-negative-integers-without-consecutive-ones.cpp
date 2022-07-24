class Solution {    
public:
    int findIntegers(int n) {
        vector<pair<int,int>>t(33);
        t[0]={1,0};
        t[1]={1,1};
        
        for(int i=2;i<32;i++){
            t[i].first=t[i-1].first+t[i-1].second;
            t[i].second=t[i-1].first;
        }
        
        int res=0;
        
        for(int i=31;i>0;i--){
            if(n&(1<<i)) {
                res+=t[i].first+t[i].second;
                if(n&(1<<(i-1))) return res+=t[i-1].first+t[i-1].second;
            }
        }
        if(n&1) return res+2;
        return res+1;        
    }
};