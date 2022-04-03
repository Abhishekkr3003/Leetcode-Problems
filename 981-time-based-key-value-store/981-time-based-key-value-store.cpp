class TimeMap {
    unordered_map<string,vector<int>>mp;
    unordered_map<string,vector<string>>mp2;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back(timestamp);
        mp2[key].push_back(value);
    }
    
    string get(string key, int timestamp) {
        if(mp[key].empty()) return "";
        auto it=upper_bound(mp[key].begin(),mp[key].end(), timestamp+1);
        if(it==mp[key].begin()) return "";
        return mp2[key][it-mp[key].begin()-1];        
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */