class Solution {
    vector<string>res;
    unordered_set<string>st;
    
    void recur(string &s, string &cur, int idx, int openCount, int closeCount, int delRemain){
        
        if(delRemain<0 || closeCount>openCount) return;
        if(idx==s.length()){
            if(openCount==closeCount && delRemain==0 && st.find(cur)==st.end()) {
                res.push_back(cur);
                st.insert(cur);
            }
            return;
        }
        
        if(s[idx]==')' || s[idx]=='('){
            recur(s,cur,idx+1,openCount,closeCount, delRemain-1);
            if(s[idx]=='(') openCount++;
            else if(s[idx]==')') closeCount++;
            cur.push_back(s[idx]);
            recur(s,cur,idx+1,openCount,closeCount,delRemain);
            cur.pop_back();
        }else{
            cur.push_back(s[idx]);
            recur(s,cur,idx+1,openCount,closeCount,delRemain);
            cur.pop_back();
        }
    }
    
public:
    vector<string> removeInvalidParentheses(string s) {
        int openCount=0;
        int del=0;
        
        for(int i=0;i<s.length();i++){
            if(s[i]=='(') openCount++;
            else if(s[i]==')'){
                if(openCount>0) openCount--;
                else del++;
            }
        }
        del+=openCount;
        
        string cur="";
        
        recur(s,cur,0,0,0,del);
        return res;
    }
};