struct Node{
    vector<Node*>children;
    Node(){
        children.resize(2,NULL);
    }
};

class Trie {
    Node *root;
public:
    Trie() {
        root=new Node();
    }
    
    void insert(int num) {
        Node *cur=root;
        for(int i=31;i>=0;i--){
            bool bit=(num&(1<<i));
            if(!cur->children[bit]) cur->children[bit]=new Node();
            cur=cur->children[bit];           
        }
    }
    
    int search(int num) {
        int res=0;
        Node *cur=root;
        for(int i=31;i>=0;i--){
            bool bit=(num&(1<<i));
            if(cur->children[!bit]) {
                res+=(1<<i);
                cur=cur->children[!bit];
            }else if(cur->children[bit]){
                cur=cur->children[bit];
            }else{
                return -1;
            }
        }
        return res;
    }
};


class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        unordered_map<int,unordered_map<int,int>>mp;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>q;
        
        for(int i=0;i<queries.size();i++){
            q.push({queries[i][1],queries[i][0]});
        }
        
        sort(nums.begin(),nums.end());
        
        int ptr=0;
        
        Trie *t=new Trie();
        
        while(!q.empty()){
            int searchVal=q.top().second;
            int pos=q.top().first;
            q.pop();
            while(ptr<nums.size() && nums[ptr]<=pos){
                t->insert(nums[ptr++]);
            }
            
            if(mp.find(pos)==mp.end() || mp[pos].find(searchVal)==mp[pos].end())
                mp[pos][searchVal]=t->search(searchVal);
        }
        
        vector<int>res(queries.size());
        for(int i=0;i<queries.size();i++){
            res[i]=mp[queries[i][1]][queries[i][0]];
        }
        
        return res;
    }
};