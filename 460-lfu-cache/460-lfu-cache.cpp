class LFUCache {
    unordered_map<int, pair<list<pair<int,int>>::iterator,int>>cache;
    unordered_map<int,list<pair<int,int>>>freq;
    int cap;
    int minFreq=0;
    
public:
    LFUCache(int capacity) {
        cap=capacity;
    }
    
    int get(int key) {
        auto it=cache.find(key);
        if(it==cache.end()) return -1;
        
        int oldFreq=it->second.second;
        int value=it->second.first->second;
        freq[oldFreq+1].push_front({key,value});
        freq[oldFreq].erase(it->second.first);
        if(freq[oldFreq].empty() && oldFreq==minFreq) minFreq++;
        cache[key]={freq[oldFreq+1].begin(),oldFreq+1};
        return freq[oldFreq+1].begin()->second;
    }
    
    void put(int key, int value) {
        if(cache.empty() && cap==0) return;
        auto it=cache.find(key);
        if(it==cache.end()) {
            if(cap==0){
                cache.erase(freq[minFreq].back().first);
                freq[minFreq].pop_back();
                cap++;
            }
            minFreq=1;
            freq[1].push_front({key,value});
            cache[key]={freq[1].begin(),1};
            cap--;
        }else{
            int oldFreq=it->second.second;
            freq[oldFreq+1].push_front({key,value});
            freq[oldFreq].erase(it->second.first);
            if(freq[oldFreq].empty() && oldFreq==minFreq) minFreq++;
            cache[key]={freq[oldFreq+1].begin(),oldFreq+1};
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */