class WordFilter {
    
    unordered_map<string,unordered_map<string,int>>mp;
    
public:
    WordFilter(vector<string>& words) {
        vector<string>suf;
        
        for(int j=0;j<words.size();j++){
            
            suf.clear();
            string suff="";
            
            for(int i=words[j].length()-1;i>=0;i--){
                suff+=words[j][i];
                suf.push_back(suff);
            }
            
            string pref="";
            
            for(int i=0;i<words[j].length();i++){
                pref+=words[j][i];
                for(string &word:suf){
                    // cout<<pref<<" "<<word<<endl;
                    mp[pref][word]=j;
                }
            }
            
        }
        
    }
    
    int f(string prefix, string suffix) {
        reverse(suffix.begin(), suffix.end());
        if(mp.find(prefix)!=mp.end()){
            if(mp[prefix].find(suffix)!=mp[prefix].end()) 
                return mp[prefix][suffix];
        }
        return -1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */