class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int>count(26,0);
        int res=0;
        int start=0;
        int maxFreq=0;
        for(int end=0;end<s.length();end++){
            count[s[end]-'A']++;
            maxFreq=max(maxFreq,count[s[end]-'A']);
            if(end-start+1-maxFreq>k){
                count[s[start]-'A']--;
                start++;
            }
            res=max(res,end-start+1);
        }
        return res;
    }
};