class Solution {
public:
    string reorganizeString(string s) {
        vector<int>freq(26,0);
        for(char ch:s) freq[ch-'a']++;
        vector<pair<int,int>>temp;
        for(int i=0;i<26;i++){
            if(freq[i]>0) temp.push_back({freq[i],i});
        }
        
        sort(temp.rbegin(),temp.rend());
        int ptr=0, size=temp[0].first;
        vector<string>res(size);
        
        for(int i=0;i<temp.size();i++){
            while(temp[i].first>0){
                res[ptr]+=('a'+temp[i].second);
                ptr=(ptr+1)%size;
                temp[i].first--;
            }
        }
        
        string ans="";
        for(string str:res){
            ans+=str;
        }
        
        // cout<<s<<endl;
        for(int i=0;i<s.length()-1;i++){
            if(ans[i]==ans[i+1]) return "";
        }
        return ans;
    }
};