/* 
    Time: O()
    Space: O()
    Tag: 
    Difficulty: 
*/

class Solution {
    bool match(string s, string t, int i) {
        // cout<<"here2\n";
        int idx1 = i;
        int idx2 = 0;
        while (idx1 < s.length() && idx2 < t.length() && s[idx1] == t[idx2]) idx1++, idx2++;
        // cout<<"here\n";
        return idx2 == t.length();
    }

public:
    string findReplaceString(string s, vector<int> &indices, vector<string> &sources, vector<string> &targets) {
        string res = "";
        unordered_map<int,pair<string,string>>mp;
        for(int i=0;i<indices.size();i++){
            mp[indices[i]]={sources[i],targets[i]};
        }
        sort(indices.begin(), indices.end());
        int ptr = 0;
        for (int i = 0; i < s.length(); i++) {
            // cout<<i<<endl;
            // cout<<indices[ptr]<<endl;
            if (ptr < indices.size() && indices[ptr] == i) {
                // cout<<"In here\n";
                if (match(s, mp[indices[ptr]].first, i)){
                    res += mp[indices[ptr]].second;
                    i+=mp[indices[ptr]].first.length();
                    i--;
                }
                else
                    res += s[i];
                // cout<<"ptr: "<<ptr<<endl;
                ptr++;
                // cout<<"ptr: "<<ptr<<endl;
            } else
                res += s[i];
            // cout<<res<<endl;
        }
        return res;
    }
};