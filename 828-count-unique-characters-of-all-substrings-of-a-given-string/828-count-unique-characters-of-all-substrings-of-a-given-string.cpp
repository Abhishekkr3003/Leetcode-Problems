class Solution {
public:
    int uniqueLetterString(string s) {
        int prev=0,cur=0;
        vector<pair<int,int>>t(26,{-1,-1});
        int res=0;
        
        for(int i=0;i<s.length();i++){
            cur=0;
            
            cur=prev-(t[s[i]-'A'].first-t[s[i]-'A'].second);
            cur+=(i-t[s[i]-'A'].first);
            
            t[s[i]-'A'].second=t[s[i]-'A'].first;
            t[s[i]-'A'].first=i;       
        
            res+=cur; 
            prev=cur;
        }
        return res;
    }
};