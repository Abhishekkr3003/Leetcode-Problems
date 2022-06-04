class Solution {
public:
    int longestPalindrome(string s) {
        vector<int>freq(128,0);
        for(int i=0;i<s.length();i++){
            freq[s[i]]++;
        }
        
        bool haveOdd=false;
        int res=0;
        for(int i=0;i<128;i++){
            if(freq[i]&1) {
                haveOdd=true;
                res+=(freq[i]-1);
            }
            else res+=freq[i];
        }
        if(haveOdd) res++;
        return res;
    }
};