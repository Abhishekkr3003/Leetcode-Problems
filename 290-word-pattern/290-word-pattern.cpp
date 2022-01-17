class Solution {
public:
    bool wordPattern(string pattern, string s) {
        
        unordered_map<string,char>strToChar;
        unordered_map<char, string>charToStr;
        int i=0;
        stringstream stream(s);
        string temp;
        while(getline(stream,temp,' ')){
            if(i>=pattern.length()) return false;
            if(strToChar.find(temp)==strToChar.end()){
                if(charToStr.find(pattern[i])==charToStr.end()){
                    charToStr[pattern[i]]=temp;
                    strToChar[temp]=pattern[i];
                }else return false;
            }else{
                if(charToStr.find(pattern[i])==charToStr.end() || (charToStr[pattern[i]]!=temp) || (strToChar[temp]!=pattern[i])) return false;
            }
            i++;
        }
        if(i<pattern.length()) return false;
        return true;
    }
};