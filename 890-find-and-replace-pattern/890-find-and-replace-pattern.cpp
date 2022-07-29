class Solution {
    
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        unordered_map<char, char>um;
        unordered_set<char>found;
        vector<string>res;
        bool flag=true;
        for(string word : words){
            //cout<<word<<"\n";
            flag=true;
            for(int i=0;i<pattern.length();i++){
                //cout<<"Word[i]: "<<word[i]<<"\n";
                if(um.find(pattern[i])!=um.end()){
                    if(um[pattern[i]]!=word[i]){
                        flag=0;
                        break;
                    }
                }
                else{
                    if(found.find(word[i])!=found.end()){
                        flag=0;
                        break;
                    }
                    um[pattern[i]]=word[i];
                    found.insert(word[i]);
                }
            }
            if(flag){
                res.push_back(word);
            }
            um.clear();
            found.clear();
        }
        return res;
    }
};