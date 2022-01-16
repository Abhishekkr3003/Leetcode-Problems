class Solution {
public:
    string convertToTitle(int columnNumber) {
        string res="";
        while(columnNumber>1){
            res+=('A'+((columnNumber-1)%26));
            columnNumber=(columnNumber-1)/26;
        }
        if(columnNumber==1) res+="A";
        reverse(res.begin(),res.end());
        return res;
    }
};