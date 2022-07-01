class Solution {
public:
    int numDecodings(string s) {
        vector<int>t(s.length()+1,0);
        if(s[0]=='0') return 0;
        
        t[0]=1;
        t[1]=1;
        for(int i=1;i<s.length();i++){
            if(s[i]=='0'){
                if((s[i-1]-'0')*10<=26 && (s[i-1]-'0')*10>0)
                    t[i+1]=t[i-1];
                else return 0;
            }else{
                if(s[i-1]=='0'){
                    t[i+1]=t[i];
                }else{
                    if(((s[i-1]-'0')*10+(s[i]-'0'))<=26){
                        t[i+1]=t[i-1]+t[i];
                    }else{
                        t[i+1]=t[i];
                    }
                }
            }
        }
        // for(int num:t) cout<<num<<endl;
        return t[s.length()];
    }
};