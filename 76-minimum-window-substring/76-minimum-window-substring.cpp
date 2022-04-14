class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> freqt(128, 0), freqs(128, 0);
        for (char ch : t) freqt[ch]++;
        int count = t.length();
        int i = 0;
        for (; i < s.length() && count; i++) {
            if (freqt[s[i]] > 0) {
                if (freqt[s[i]] > freqs[s[i]]) count--;
                freqs[s[i]]++;
            }
        }
        if (count > 0) {
            return "";
        }
        int start = 0, len = i - start, minLenStart = 0;
        
        while (freqt[s[start]] <= 0 || freqt[s[start]] < freqs[s[start]]) {
            freqs[s[start++]]--;
            // cout<<"here";
            if (i - start < len) {
                len = i - start;
                minLenStart = start;
            }
        }
        
        for (; i < s.length(); i++) {
            // cout<<"here";
            // cout << i << " " << start << endl;
            freqs[s[i]]++;
            while (freqt[s[start]] <= 0 || freqt[s[start]] < freqs[s[start]]) {
                freqs[s[start++]]--;
            }
            if (i - start +1< len) {
                len = i - start + 1;
                minLenStart = start;
            }
        }
        // cout << minLenStart << " " << len << endl;
        while (freqt[s[start]] <= 0 || freqt[s[start]] < freqs[s[start]]) {
            freqs[s[start++]]--;
            // cout<<"here";
            if (s.length() - start < len) {
                len = s.length() - start;
                minLenStart = start;
            }
        }
        // cout<<start<<endl;
        // cout << minLenStart << " " << len << endl;
        return s.substr(minLenStart, len);
    }
};