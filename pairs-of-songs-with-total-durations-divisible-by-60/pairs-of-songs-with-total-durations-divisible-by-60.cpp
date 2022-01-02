class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        for(int i=0;i<time.size();i++) time[i]=time[i]%60;
        vector<int>count(60,0);
        for(int i=0;i<time.size();i++) count[time[i]]++;
        int res=0;
        for(int i=0;i<=30;i++){
            if(i==0 || i==30) res+=(count[i]*(count[i]-1))/2;
            else res+=count[i]*count[60-i];
            // cout<<res<<endl;
        }
        return res;        
    }
};