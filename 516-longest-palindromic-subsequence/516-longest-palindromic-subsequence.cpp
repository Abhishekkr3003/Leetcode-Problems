class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string rev=s;
        reverse(rev.begin(),rev.end());
        int n=s.length();
        
        vector<int>t(n+1,0), temp(n+1,0);
        
        int res=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(s[i]==rev[j]){
                    temp[j+1]=1+t[j];
                }else{
                    temp[j+1]=max(temp[j], t[j+1]);
                }
                res=max(res,temp[j+1]);
            }
            t=temp;
        }
        return res;
    }
};