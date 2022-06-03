class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>res;
        unordered_map<string,vector<string>>mp;
        for(string &str:strs){
            string temp=str;
            sort(str.begin(), str.end());
            mp[str].push_back(temp);
        }
        for(auto &p:mp){
            res.push_back(p.second);
        }
        return res;
    }
};