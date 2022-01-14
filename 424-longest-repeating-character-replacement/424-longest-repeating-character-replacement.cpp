class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int>freq(26,0);
        int maxFreq=0;
        int start=0;
        int res=0;
        int i=0;
        while(i<s.length()){
            freq[s[i]-'A']++;
            maxFreq=max(maxFreq,freq[s[i]-'A']);
            if(i+1-start-maxFreq>k){
                freq[s[start]-'A']--;
                start++;
            }
            res=max(res,i-start+1);
            i++;
        }
        return res;
    }
};