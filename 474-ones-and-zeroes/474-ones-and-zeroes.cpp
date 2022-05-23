class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int res=0;
        vector<vector<int>>t(m+1,vector<int>(n+1,0));
        for(string &str:strs){
            int zeros=0;
            int ones=0;
            for(int i=0;i<str.length();i++){
                if(str[i]=='0') zeros++;
            }
            ones=str.length()-zeros;
            for(int i=m;i>=zeros;i--){
                for(int j=n;j>=ones;j--){
                    t[i][j]=max(t[i][j],1+t[i-zeros][j-ones]);
                    res=max(res,t[i][j]);
                }
            }
        }
        return res;
    }
};