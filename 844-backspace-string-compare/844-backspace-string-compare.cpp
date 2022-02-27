class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int count1=0, count2=0;
        int i=s.length()-1, j=t.length()-1;
        while(i>=0 && j>=0){
            if(s[i]=='#') count1++, i--;
            else if(t[j]=='#') count2++, j--;
            else if(count1>0) count1--, i--;
            else if(count2>0) count2--, j--;
            else if(s[i]!=t[j]) {
                // cout<<"here";
                return false;
            }else i--, j--;
        }
        if(i>=0){
            if(s[i]=='#') count1++, i--;
            else count1--, i--;
            if(count1<0) return false;
        }
        while(j>=0){
            if(t[j]=='#') count2++, j--;
            else count2--, j--;
            if(count2<0) return false;
        }
        return true;
    }
};