class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        unordered_set<string>st;
        for(string &word:wordDict){
            reverse(word.begin(),word.end());
            st.insert(word);
        }
        
        vector<bool>t(s.length()+1,false);
        
        t[0]=true;
        
        for(int i=0;i<s.length();i++){
            string cur=s.substr(0,i+1);
            reverse(cur.begin(),cur.end());
            for(int j=0;j<=i;j++){
                if(st.find(cur)!=st.end()){
                    t[i+1]=t[i+1]||t[j];
                    if(t[i+1]) break;
                }
                cur.pop_back();
            }
        }
        return t[s.length()];
    }
};