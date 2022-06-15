class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int>prior(26,0);
        for(int i=0;i<order.length();i++){
            prior[order[i]-'a']=i;
        }
        
        for(int i=0;i<words.size()-1;i++){
            
            int j=0;
            while(j<min(words[i].length(),words[i+1].length()) && words[i][j]==words[i+1][j]) j++;
            
            if(j==min(words[i].length(),words[i+1].length())){
                if(words[i].length()>words[i+1].length()) return false;
                continue;
            }            
            else if(prior[words[i][j]-'a']>prior[words[i+1][j]-'a']) return false;
        }
        
        return true;
    }
};