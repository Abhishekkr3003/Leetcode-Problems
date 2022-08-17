class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string>codes={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        int res=0;
        unordered_set<string>st;
        
        
        for(int i=0;i<words.size();i++){
            string tempWord="";
            
            for(char &ch:words[i]){
                tempWord+=codes[ch-'a'];
            }
            
            st.insert(tempWord);
        }
        return st.size();
    }
};