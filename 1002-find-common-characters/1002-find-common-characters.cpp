class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int>freq1(26,0), freq2(26,0);
        
        for(int i=0;i<words[0].length();i++){
            freq1[words[0][i]-'a']++;
        }
        
        for(int i=1;i<words.size();i++){
            for(int j=0;j<26;j++) freq2[j]=0;
            for(char ch:words[i]) freq2[ch-'a']++;
            for(int j=0;j<26;j++) freq1[j]=min(freq1[j],freq2[j]);
        }
        
        vector<string>res;
        
        for(int i=0;i<26;i++){
            while(freq1[i]--){
                string s(1,'a'+i);
                res.push_back(s);
            }
        }
        return res;
    }
};