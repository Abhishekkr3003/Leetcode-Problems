class Solution {
    void solve(int i, string cur, string s, vector<string>&res){
        if(i==s.length()) {res.push_back(cur); return;}
        if(isalpha(s[i])){
            solve(i+1,cur+(char)toupper(s[i]),s,res);
            solve(i+1,cur+(char)tolower(s[i]),s,res);
        } else solve(i+1,cur+s[i],s,res);
    }
public:
    vector<string> letterCasePermutation(string s) {
        vector<string>res;
        solve(0,"",s,res);
        return res;
    }
};