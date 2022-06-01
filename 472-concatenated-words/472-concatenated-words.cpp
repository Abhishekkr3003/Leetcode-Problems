class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        sort(words.begin(),words.end(), [](string &a, string &b){
            return a.length()<b.length();
        });
        vector<string>res;
        set<string>st;
        for(string &s:words){
            if(s.length()==0) continue;
            vector<bool>t(s.length()+1,false);
            // cout<<s<<endl;
            t[0]=true;
            for(int i=0;i<s.length();i++){
                for(int j=0;j<=i;j++){
                    string temp=s.substr(j,i-j+1);
                    if(st.find(temp)!=st.end()){
                        t[i+1]=t[i+1]||t[j];
                        if(t[i+1]) break;
                    }
                }
            }
            if(t[s.length()]) res.push_back(s);
            st.insert(s);
        }
        return res;
    }
};