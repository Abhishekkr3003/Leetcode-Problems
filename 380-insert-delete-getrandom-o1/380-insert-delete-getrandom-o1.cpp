
class RandomizedSet {
    unordered_map<int,int>mp;
    vector<int>arr;
    
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.find(val)!=mp.end()) return false;
        arr.push_back(val);
        mp[val]=arr.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(mp.find(val)==mp.end()) return false;
        int index=mp[val];
        mp[arr.back()]=index;
        arr[index]=arr.back();
        arr.pop_back();
        mp.erase(val);
        return true;
    }
    
    int getRandom() {
        int rNo = rand();
        rNo = (rNo % arr.size());
        // cout << rNo << endl;
        return *(arr.begin() + rNo);
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */