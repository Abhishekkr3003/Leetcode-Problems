/* 
    Time: O(m+nlogn)
    Space: O(m+n)
    Tag: String Manipulation
    Difficulty: M
*/

class Solution {
    bool match(string s, string t, int i) {
        int idx1 = i;
        int idx2 = 0;
        while (idx1 < s.length() && idx2 < t.length() && s[idx1] == t[idx2]) idx1++, idx2++;
        return idx2 == t.length();
    }

public:
    string findReplaceString(string s, vector<int> &indices, vector<string> &sources, vector<string> &targets) {
        string res = "";
        unordered_map<int,pair<string,string>>mp;
        for(int i=0;i<indices.size();i++){
            mp[indices[i]]={sources[i],targets[i]};
        }
        for (int i = 0; i < s.length(); i++) {
            if (mp.find(i)!=mp.end()) {
                if (match(s, mp[i].first, i)){
                    res += mp[i].second;
                    i+=mp[i].first.length();
                    i--;
                }
                else
                    res += s[i];
            } else
                res += s[i];
        }
        return res;
    }
};