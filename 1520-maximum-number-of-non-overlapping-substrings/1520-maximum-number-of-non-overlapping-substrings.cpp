class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        vector<pair<int,int>>t(26,{-1,-1});
        vector<pair<int,int>>pos(26,{INT_MAX,INT_MAX});
        
        
        for(int i=0;i<s.length();i++){
            if(t[s[i]-'a'].second==-1){
                t[s[i]-'a']={i,i};
                pos[s[i]-'a']={i,s[i]-'a'};
            }else{
                t[s[i]-'a'].second=i;
            }
        }
        sort(pos.begin(),pos.end());
        
        // for(auto p:pos) cout<<p.first<<" "<<p.second<<endl;
        
        vector<pair<int,int>>ranges;
        for(int i=0;i<pos.size();i++){
            if(pos[i].first==INT_MAX) continue;
            pair<int,int>range=t[pos[i].second];
            for(int j=t[pos[i].second].first;j<t[pos[i].second].second;j++){
                range.first=min(range.first, t[s[j]-'a'].first);
                range.second=max(range.second, t[s[j]-'a'].second);
            }
            t[pos[i].second]=range;
        }
        for(int i=0;i<pos.size();i++){
            if(pos[i].first==INT_MAX) continue;
            pair<int,int>range=t[pos[i].second];
            for(int j=t[pos[i].second].first;j<t[pos[i].second].second;j++){
                range.first=min(range.first, t[s[j]-'a'].first);
                range.second=max(range.second, t[s[j]-'a'].second);
            }
            t[pos[i].second]=range;
            ranges.push_back(range);
        }
        
        // for(auto p:ranges) cout<<p.first<<" "<<p.second<<endl;
        
        sort(ranges.begin(),ranges.end(), [](auto &a, auto&b){
            return (a.second-a.first<b.second-b.first);
        });
        
        // for(auto p:ranges)cout<<p.first<<" "<<p.second<<endl;
        
        vector<pair<int,int>>p;
        
        for(int i=0;i<ranges.size();i++){
            bool canPut=true;
            for(int j=0;j<p.size();j++){
                if(ranges[i].first>p[j].second || ranges[i].second<p[j].first) continue;
                canPut=false;
                break;
            }
            if(canPut) p.push_back(ranges[i]);
        }
        vector<string>res(p.size());
        
        for(int i=0;i<p.size();i++){
            res[i]=s.substr(p[i].first, p[i].second-p[i].first+1);
        }
        return res;
    } 
};