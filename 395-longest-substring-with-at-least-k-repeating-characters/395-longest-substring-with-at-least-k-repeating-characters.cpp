// H | Sliding Window | Time: O(n) | Space: O(1)

class Solution {
public:
    int longestSubstring(string s, int k) {
        int res=0;
        unordered_set<int>st;
        for(char ch:s) st.insert(ch);
        vector<int> freq;
        for (int i = 1; i <= st.size(); i++) {
            int start=0,end=0;
            freq.clear();
            freq.resize(26, 0);
            int uniqueCount = 0;
            while (end < s.length()) {
                freq[s[end]-'a']++;
                if (freq[s[end] - 'a'] == 1) uniqueCount++;
                end++;
                while(uniqueCount>i){
                    freq[s[start] - 'a']--;
                    if (freq[s[start] - 'a'] == 0) uniqueCount--;
                    start++;
                }
                if (end-start>=k*uniqueCount) {
                    bool countIt=true;
                    for(int f:freq) {
                        // cout<<"f: "<<f<<endl;
                        if(f>0 && f<k) {
                            countIt=false;
                            break;
                        }
                    }
                    if(countIt)
                        res = max(res, end - start);
                }
                // cout<<res<<endl;
            }
        }
        return res;
    }
};