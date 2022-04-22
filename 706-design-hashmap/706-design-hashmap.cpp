class MyHashMap {
    vector<pair<int,int>>hashMap[10000];
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        remove(key);
        int hashCode=key%10000;
//         for(auto p:hashMap[hashCode])
//         {
//             cout<<key<<" "<<value<<"\n";
//             if (p.first==key)
//             {
//                 p.second=value;
//                 cout<<p.first<<" "<<p.second<<"\n";
                
//                 return;
//             }
//         }
        hashMap[hashCode].push_back({key, value});
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int hashCode=key%10000;
        for(auto p:hashMap[hashCode])
        {
            //cout<<"Deletion: "<<p.first<<" "<<p.second<<"\n";
            if (p.first==key)
                return p.second;
        }
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int hashCode=key%10000;
        vector<pair<int, int>>::iterator it;
        for(it=hashMap[hashCode].begin(); it!=hashMap[hashCode].end();it++)
        {
            if(it->first==key)
            {
                hashMap[hashCode].erase(it);
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */