class Solution {
public:
    string reverseWords(string s) {
        int n=s.length();
        int i=0, j=0;
        while(i<n){
            while(i<n && s[i]!=' ') i++;
            int start=j, end=i-1;
            while(start<end) swap(s[start++],s[end--]);
            j=i+1;
            i=j;
        }
        return s;
    }
};