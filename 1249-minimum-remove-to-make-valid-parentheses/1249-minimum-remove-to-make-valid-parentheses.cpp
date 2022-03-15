class Solution {
public:
    string minRemoveToMakeValid(string s) {
        vector<pair<int,char>>st;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(') st.push_back({i,'('});
            else if(s[i]==')'){
                // cout<<"hrer2\n";
                if(!st.empty() &&(st.back()).second=='(') st.pop_back();
                else st.push_back({i,')'});
            }
        }
        string res="";
        int j=0;
        // cout<<"here";
        for(int i=0;i<s.length();i++){
            if(j<st.size() && i==st[j].first){
                j++;
            }else{
                res+=s[i];
            }
        }
        return res;
    }
};