class Solution {
public:
    string simplifyPath(string path) {
        stringstream s(path);
        vector<string>st;
        string str;
        while(getline(s,str,'/')){
            if(str=="" || str==".") continue;
            else if(str=="..") {
                if(st.empty()) continue;
                st.pop_back();
            }
            else st.push_back(str);
        }
        if(st.empty()) return "/";
        string res="/";
        for(int i=0;i<st.size()-1;i++){
            res+=st[i];
            res+="/";
        }
        res+=st.back();
        return res;
    }
};