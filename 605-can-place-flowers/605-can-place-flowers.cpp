class Solution {
public:
    bool canPlaceFlowers(vector<int>& f, int n) {
        int res=0;
        int curCount=0;
        int i=0;
        while(i<f.size() && !f[i]) i++;
        res+=i/2;
        if(i==f.size()) return ceil(i/2.0)>=n;
        for(;i<f.size();i++){
            // cout<<curCount<<endl;
            if(!f[i]) curCount++;
            else if(curCount>2){
                res+=(curCount-1)/2;
                curCount=0;
            }
            else curCount=0;
        }
        res+=curCount/2;
        // cout<<res<<endl;
        return res>=n;
    }
};