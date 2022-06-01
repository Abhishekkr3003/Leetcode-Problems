class LRUCache {
    list<int>q;
    unordered_map<int,pair<int,list<int>::iterator>>mapping;
    int capacity;
public:
    LRUCache(int capacity) {
        this->capacity=capacity;
    }
    
    int get(int key) {
        auto it=mapping.find(key);
        if(it==mapping.end()) return -1;
        q.push_back(key);
        q.erase(it->second.second);
        mapping[key].second=prev(q.end());
        return mapping[key].first;
    }
    
    void put(int key, int value) {
        auto it=mapping.find(key);
        if(it==mapping.end()){
            if(capacity>0){
                q.push_back(key);
                mapping[key]={value,prev(q.end())};
                capacity--;
            }else{
                mapping.erase(q.front());
                q.erase(q.begin());
                q.push_back(key);
                mapping[key]={value,prev(q.end())};
            }
        }else{
            q.push_back(key);
            q.erase(it->second.second);
            mapping[key]={value, prev(q.end())};
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */