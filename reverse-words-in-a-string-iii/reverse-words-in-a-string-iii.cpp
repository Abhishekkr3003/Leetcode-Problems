class Solution {
public:
    string reverseWords(string s) {
        stringstream rev(s);
        string word;
        string res="";
        while(getline(rev,word,' ')){
            reverse(word.begin(),word.end());
            res+=word+" ";
        }
        res.pop_back();
        return res;
    }
};