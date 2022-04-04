typedef long long ll;

class Solution {
    int possible(string &s, int len){
        ll p=26, mod=1e9+7;
        ll power=1;
        ll hash=0;
        int i=s.length()-len;
        for(;i<s.length()-1;i++){
            hash=(hash+(s[i]-'a'+1)*power)%mod;
            power=(power*p)%mod;
        }
        hash=(hash+(s[i]-'a'+1)*power)%mod;
        unordered_map<int,vector<int>>mp;
        mp[hash].push_back(s.length()-len);
        for(i=s.length()-len-1;i>=0;i--){
            hash=(mod+hash-((s[i+len]-'a'+1)*power)%mod)%mod;
            hash=(hash*p)%mod;
            hash=(hash+(s[i]-'a'+1))%mod;
            if(mp.find(hash)!=mp.end()) {
                string tmp=s.substr(i,len);
                for(int start:mp[hash]){
                    if(s.substr(start,len)==tmp) return start;
                }
            }
            mp[hash].push_back(i);
        }
        return -1;
    }
    
public:
    string longestDupSubstring(string s) {
        int lo=0, hi=s.length();
        int mid=0;
        string res="";
        int start=-1;
        int len=-1;
        while(lo<=hi){
            mid=lo+(hi-lo)/2;
            // if(mid==0) return possible(s,1);
            int temp=possible(s,mid);
            if(temp!=-1) {
                start=temp;
                len=mid;
                lo=mid+1;
            }else hi=mid-1;
        }
        return len==-1?"":s.substr(start,len);
    }
};