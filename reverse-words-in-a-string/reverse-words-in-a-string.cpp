class Solution {
public:
    string reverseWords(string s) {
        for(int i=0;i<s.length()/2;i++) swap(s[i],s[s.length()-1-i]);
        int start,end;
        // cout<<s<<endl;
        for(int i=0;i<s.length();i++){
            while(i<s.length() && isspace(s[i])) i++;
            start=i;
            while(i<s.length() && !isspace(s[i])) i++;
            end=i-1;
            while(start<end) swap(s[start++],s[end--]); 
        }
        // cout<<s<<endl;
        int spaceCount=0;
        bool space=false;
        for(int i=0; i<s.length();i++){
            if(isspace(s[i])){
                if(!space) {
                    spaceCount++;
                }else {
                    s[i-spaceCount]=s[i];
                    space=false;
                }
            }else{
                s[i-spaceCount]=s[i];
                space=true;
            }
        }
        while(spaceCount--) s.pop_back();
        if(isspace(s.back())) s.pop_back();
        return s;
    }
};