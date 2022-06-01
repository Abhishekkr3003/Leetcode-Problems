class Solution {
public:
    int minFlipsMonoIncr(string s) {
        vector<int>prefix(s.length()+2);
        prefix[0]=0;
        for(int i=0;i<s.length();i++){
            prefix[i+1]=prefix[i]+(s[i]=='1'?1:0);
        }
        prefix[s.length()+1]=prefix[s.length()];
        int res=INT_MAX;
        for(int i=1;i<=s.length()+1;i++){
            res=min(res, (int)(prefix[i-1]+s.length()-i+1-(prefix.back()-prefix[i-1])));
        }
        return res;
    }
};