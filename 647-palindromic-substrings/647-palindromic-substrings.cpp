class Solution {
    int expand(string &s, int i, int j){
        int res=1;
        while(i>=0 && j<s.length() && s[i]==s[j]){
            i--,j++;
            res++;
        }
        return res;
    }
public:
    int countSubstrings(string s) {
        int res=0;
        int i=0;
        for(;i<s.length()-1;i++){
            res+=expand(s,i-1,i+1);
            if(s[i]==s[i+1]) res+=expand(s,i-1,i+2);
        }
        res+=expand(s,i-1,i+1);
        return res;
    }
};