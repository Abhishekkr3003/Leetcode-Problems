class Solution {
public:
    int minTaps(int n, vector<int>& range) {
        vector<int>t(n+1,INT_MAX-1);
        t[0]=0;
        
        for(int i=0;i<range.size();i++){
            int curMinOpen=t[max(0,i-range[i])]+1;
            
            for(int j=max(0,i-range[i]);j<=min(n,i+range[i]);j++){
                t[j]=min(t[j],curMinOpen);
            }
        }
        return t[n]==INT_MAX-1?-1:t[n];
    }
};