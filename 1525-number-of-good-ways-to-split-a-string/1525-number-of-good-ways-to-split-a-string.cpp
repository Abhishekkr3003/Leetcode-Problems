class Solution {
public:
    int numSplits(string s) {
        vector<int>uniqCount(s.length(),0);
        
        vector<int>freq(26,0);
        
        freq[s[0]-'a']++;
        uniqCount[0]=1;
        for(int i=1;i<s.length();i++){
            if(freq[s[i]-'a']==0) {
                uniqCount[i]=uniqCount[i-1]+1;
            }else{
                uniqCount[i]=uniqCount[i-1];
            }
            freq[s[i]-'a']++;
        }
        
        freq.clear();
        freq.resize(26,0);
        
        int curCount=0, res=0;
        
        for(int i=s.length()-1;i>=1;i--){
            if(freq[s[i]-'a']==0) {
                curCount++;
            }
            if(uniqCount[i-1]==curCount) res++;
            freq[s[i]-'a']++;
        }
        return res;
    }
};