class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string>ban;
        int maxLen=0;
        string res="";
        for(string s:banned) ban.insert(s);
        unordered_map<string,int>mp;
        string word="";
        for(int i=0;i<paragraph.length();i++){
            word="";
            while(i<paragraph.length() && isalpha(paragraph[i])){
                word+=tolower(paragraph[i++]);
            }
            // cout<<word<<endl;
            if(word.length()>0 && ban.find(word)==ban.end()) {
                mp[word]++;
                if(mp[word]>maxLen){
                    maxLen=mp[word];
                    res=word;
                }
            }
            // cout<<mp[word]<<endl;
        }
        return res;
    }
};