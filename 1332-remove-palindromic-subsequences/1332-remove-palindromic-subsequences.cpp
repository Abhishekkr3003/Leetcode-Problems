class Solution {
public:
    int removePalindromeSub(string s) {
        int lo=0, hi=s.length()-1;
        while(lo<hi){
            if(s[lo++]!=s[hi--]) return 2;
        }
        return 1;
    }
};