class AllOne {
    unordered_map<string,pair<list<string>::iterator,int>>freq;
    unordered_map<int,list<string>>lists;
    list<int>count;
    unordered_map<int,list<int>::iterator>countExists;
    
public:
    AllOne() {
    }
    
    void inc(string key) {
        // cout<<"inc: "<<key<<endl;
        if(freq.find(key)==freq.end()){
            lists[1].push_back(key);
            freq[key]={prev(lists[1].end()),1};
            if(countExists.find(1)==countExists.end()) {
                count.push_front(1);
                countExists[1]=count.begin();
            }
            return;
        }
        
        int oldFreq=freq[key].second;
        lists[oldFreq].erase(freq[key].first);
        lists[oldFreq+1].push_back(key);
        freq[key]={prev(lists[oldFreq+1].end()),oldFreq+1}; 
        if(countExists.find(oldFreq+1)==countExists.end()){
            auto it=countExists[oldFreq];
            count.insert(++it,oldFreq+1);
            it=countExists[oldFreq];
            countExists[oldFreq+1]=++it;
        }
        if(lists[oldFreq].empty()){
            count.erase(countExists[oldFreq]);
            countExists.erase(oldFreq);
        }
        // cout<<count.front()<<endl;
    }
    
    void dec(string key) {
        // cout<<"dec: "<<key<<endl;
        int oldFreq=freq[key].second;
        lists[oldFreq].erase(freq[key].first);
        if(oldFreq==1){
            // cout<<"here\n";
            freq.erase(key);
            if(lists[1].empty()){
                // cout<<"there2\n";
                // cout<<count.front()<<endl;
                count.erase(countExists[1]);
                // cout<<"here3\n";
                countExists.erase(1);
                // cout<<"bye\n";
            }
        }else{
            lists[oldFreq-1].push_back(key);
            freq[key]={prev(lists[oldFreq-1].end()),oldFreq-1};
            if(countExists.find(oldFreq-1)==countExists.end()){
                auto it=countExists[oldFreq];
                count.insert(it,oldFreq-1);
                it=countExists[oldFreq];
                countExists[oldFreq-1]=--it;
            }
            if(lists[oldFreq].empty()){
                // cout<<"Here: "<<oldFreq<<count.front()<<endl;
                count.erase(countExists[oldFreq]);
                // cout<<count.front()<<endl;
                countExists.erase(oldFreq);
                // cout<<count.front()<<endl;
            }
        } 
        // cout<<count.front()<<endl;
    }
    
    string getMaxKey() {
        if(count.empty()) return "";
        return lists[count.back()].back();
    }
    
    string getMinKey() {
        if(count.empty()) return "";
        return lists[count.front()].back();
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */