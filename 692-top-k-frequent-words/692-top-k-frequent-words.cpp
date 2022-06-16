class comp{
public:
    
    bool operator()(pair<int,string>&a, pair<int,string>&b){
        if(a.first!=b.first) return a>b;
        return a.second<b.second;
    }
};

class Solution {
    
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int>freq;
        for(string &word:words) freq[word]++;
        
        priority_queue<pair<int,string>, vector<pair<int,string>>, comp>q;
        
        for(auto p:freq){
            q.push({p.second,p.first});
            if(q.size()>k) q.pop();
        }
        vector<string>res;
        while(!q.empty()) {
            res.push_back(q.top().second);
            q.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};