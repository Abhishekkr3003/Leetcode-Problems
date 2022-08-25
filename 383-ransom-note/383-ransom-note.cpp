class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int>freq1(26,0);
        for(char &ch:magazine){
            freq1[ch-'a']++;
        }
        
        for(char &ch:ransomNote){
            freq1[ch-'a']--;
            if(freq1[ch-'a']<0) return false;
        }
        return true;
    }
};