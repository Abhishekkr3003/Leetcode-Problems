class Solution {
public:
    int minDeletions(string s) {
        int n=s.length();
        vector<int>freq(26,0);
        for(char &ch:s){
            freq[ch-'a']++;
        }
        map<int,int>mp;
        for(int num:freq) {
            if(num!=0)
                mp[-num]++;
        }
        int res=0;
        for(auto p:mp){
            // cout<<p.first<<" "<<p.second<<endl;
            if(p.first==0) break;
            if(p.second>1) {
                res+=p.second-1;
                mp[p.first+1]+=p.second-1;
            }
        }
        return res;
    }
};