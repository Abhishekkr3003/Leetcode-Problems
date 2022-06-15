class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        // if(s.length()<words.size()*words[0].length()) return {};
        
        unordered_map<string,int>allWords;
        
        int wordLen=words[0].length();
        
        vector<int>res;
        
        for(string &word:words) allWords[word]++;
        bool found=true;
        // cout<<s.length()<<" "<<words.size()*wordLen<<endl;
        int threshold=(s.length()-(words.size()*wordLen));
        // cout<<threshold<<endl;
        for(int i=0;i<=threshold;i++){
            // cout<<"here\n";
            found=true;
            unordered_map<string,int>searchFor=allWords;
            
            for(int j=i;j<i+words.size()*wordLen;j+=wordLen){
                
                string curWord=s.substr(j,wordLen);
                if(searchFor[curWord]<=0) {
                    found=false;
                    break;
                }else{
                    searchFor[curWord]--;
                }
                
            }
            if(found) res.push_back(i);
            
        }
        return res;        
    }
};