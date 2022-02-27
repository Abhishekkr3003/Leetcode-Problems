class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>freq(128,0);
        for(char ch:p) freq[ch]++;
        int i=0, j=0;
        int needed=p.length();
        vector<int>freq2(128,0);
        vector<int>res;
        while(j<s.length()){
            if(freq2[s[j]]<freq[s[j]]) needed--;
            freq2[s[j]]++;
            while(freq2[s[j]]>freq[s[j]]){
                // cout<<s[i]<<endl;
                freq2[s[i]]--;
                if(freq2[s[i]]<freq[s[i]] && freq[s[i]]) needed++;
                i++;
            }
            j++;
            // cout<<needed<<endl;
            if(needed==0) res.push_back(i);
        }
        return res;
    }
};