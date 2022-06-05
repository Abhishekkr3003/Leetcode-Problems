class Solution {
    string ans="";
    
    bool check(string &s, int len){
        unordered_map<int,vector<int>>mp;
        long long hash=0;
        int mod=1e9+7;
        int pm=26;
        long long p=1;
        for(int i=s.length()-len;i<s.length();i++){
            hash=(hash+(s[i]-'a'+1)*p)%mod;
            if(i==s.length()-1) break;
            p=(p*pm)%mod;
        }
        mp[hash].push_back(s.length()-len);
        for(int i=s.length()-len-1;i>=0;i--){
            hash=(hash-((s[i+len]-'a'+1)*p)%mod+mod)%mod;
            hash=((hash%mod)*(pm%mod))%mod;
            hash=(hash+(s[i]-'a'+1))%mod;
            auto it=mp.find(hash);
            if(it!=mp.end()){
                string cur=s.substr(i,len);
                for(int &num: it->second){
                    if(s.substr(num,len)==cur){
                        ans=cur;
                        return true;
                    }
                }
                
            }
            mp[hash].push_back(i);
        }
        return false;
    }
    
public:
    string longestDupSubstring(string s) {
        int lo=0, hi=s.length();
        int mid=0;
        
        
        while(lo<=hi){
            mid=lo+(hi-lo)/2;
            
            if(check(s,mid)) lo=mid+1;
            else hi=mid-1;
            
        }
        return ans;
    }
};