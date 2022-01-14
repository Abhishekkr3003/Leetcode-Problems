class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        int res=0;
        int n=s.length();
        while(i<n && isspace(s[i])) i++;
        if(i>=n) return 0;
        bool sign=false;
        if(s[i]=='-') {
            sign=true;
            i++;
        }else if(s[i]=='+') i++;
        while(i<n && isdigit(s[i])){
            if(!sign) res=min((long)INT_MAX, (long)res*10+(s[i]-'0'));
            else res=max((long)INT_MIN,-((long)res*10+(s[i]-'0')));
            // cout<<res<<endl;
            if(res==INT_MAX || res==INT_MIN) return res;
            res=abs(res);
            i++;
        }
        return sign?-res:res;
    }
};