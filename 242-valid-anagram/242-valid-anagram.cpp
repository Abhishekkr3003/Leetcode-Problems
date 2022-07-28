class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length())
            return false;
        vector<int> v(26,0);
        for(auto ch:s)
        {
            v[ch-97]++;
        }
        for(auto ch:t)
        {
            if(v[ch-97]<=0)
                return false;
            v[ch-97]--;
        }
        return true;
    }
};