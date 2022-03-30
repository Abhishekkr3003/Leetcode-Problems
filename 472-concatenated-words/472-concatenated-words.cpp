class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<bool> t;
        unordered_set<string> st;
        vector<string> res;
        sort(words.begin(), words.end(), [](string a, string b) {
            return a.length() < b.length();
        });
        // for (auto str : words)
        //     cout << str << " ";
        int index = 0;
        int smallestLength = words[0].length();
        while (index < words.size() && words[index].length() == smallestLength) {
            st.insert(words[index++]);
        }
        for (; index < words.size(); index++) {
            t.resize(words[index].length() + 1, false);
            t[0] = true;
            for (int i = 1; i <= words[index].length(); i++) {
                for (int j = 0; j < i; j++) {
                    if(t[j]){
                        string substring = words[index].substr(j, i - j);
                        if (st.find(substring) != st.end()) {
                            t[i] = true;
                            break;
                        }
                    }
                }
            }

            if (t[words[index].size()]) {
                res.push_back(words[index]);
            }
            st.insert(words[index]);
            t.clear();
        }
        return res;
    }
};