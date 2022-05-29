class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> freq(128, 0);
        for (char ch : t) freq[ch]++;
        bool found;
        int i = 0;
        for (; i < s.length(); i++) {
            freq[s[i]]--;
            found = true;
            for (int j = 0; j < 128; j++) {
                if (freq[j] > 0) {
                    found = false;
                    break;
                }
            }
            if (found) break;
        }
        if (found == false) {
            return "";
        }
        int start = 0;
        while (freq[s[start]] < 0) {
            freq[s[start]]++;
            start++;
        }
        int res = i - start + 1;
        string resStr = s.substr(start, res);
        // cout << "res: " << res << endl;
        i++;
        for (; i < s.length(); i++) {
            freq[s[i]]--;
            freq[s[start++]]++;
            found = true;
            for (int j = 0; j < 128; j++) {
                if (freq[j] > 0) {
                    found = false;
                    break;
                }
            }
            if (res > i - start + 1) {
                res = i - start + 1;
                resStr = s.substr(start, res);
            }
            if (found) {
                while (freq[s[start]] < 0) {
                    freq[s[start]]++;
                    start++;
                }
            }
            if (res > i - start + 1) {
                res = i - start + 1;
                resStr = s.substr(start, res);
            }
            // cout << resStr << endl;
        }
        found = true;
        for (int j = 0; j < 128; j++) {
            if (freq[j] > 0) {
                found = false;
                break;
            }
        }
        if (found == true) {
            while (freq[s[start]] < 0) {
                freq[s[start]]++;
                start++;
            }
        }
        // cout << start << endl;
        if (res > (int)s.length() - start) {
            res = (int)s.length() - start;
            resStr = s.substr(start, res);
        }
        return resStr;
    }
};