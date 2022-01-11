class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length()>s2.length()) return false;
        vector<int>sOne(26);
        vector<int>sTwo(26);
        int n=s1.length();  
        int i=0;
        for(;i<n;i++){
            sOne[s1[i]-'a']++;
            sTwo[s2[i]-'a']++;
        }
        if(sOne==sTwo) return true;
        for(;i<s2.length();i++){
            sTwo[s2[i-n]-'a']--;
            sTwo[s2[i]-'a']++;
            if(sOne==sTwo) return true;
        }
        return false;
    }
};