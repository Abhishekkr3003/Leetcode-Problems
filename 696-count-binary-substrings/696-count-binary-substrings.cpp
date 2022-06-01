class Solution {
public:
    int countBinarySubstrings(string s) {
        int ones=0, zeros=0, res=0;
        if(s[0]=='1') ones++;
        else zeros++;
        for(int i=1;i<s.length();i++){
            if(s[i]!=s[i-1]){
                res+=min(ones,zeros);
                if(s[i-1]=='1') zeros=0;
                else ones=0;
            }
            if(s[i]=='1') ones++;
            else zeros++;
        }
        res+=min(ones,zeros);
        return res;
    }
};