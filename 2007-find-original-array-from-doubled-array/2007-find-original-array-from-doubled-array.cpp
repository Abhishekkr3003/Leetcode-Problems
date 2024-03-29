class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        map<int,int>mp;
        for(int i=0;i<changed.size();i++) mp[changed[i]]++;
        
        vector<int>res;
        
        for(auto p:mp){
           if(p.first==0){
               if(p.second&1) return {};
               else{
                   for(int i=0;i<p.second/2;i++) res.push_back(0);
               }
           }
            
           else if(p.second>0){
               mp[2*p.first]-=p.second;
               if(mp[2*p.first]<0) return {};
               else {
                   for(int i=0;i<p.second;i++) res.push_back(p.first);
               }
           } 
        }
        return res;
    }
};