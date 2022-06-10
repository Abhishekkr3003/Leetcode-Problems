class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty())
            return 0;
        unordered_set<char>t;
        int si=0, ei=1, count=1, res=0;
        t.insert(s[0]);
        while(ei<s.length()){
            // cout<<s[ei]<<endl;
            if(t.find(s[ei])!=t.end()){
                res=max(res, count);
                while(s[si]!=s[ei]){
                    count--;
                    // cout<<"removing: "<<s[si]<<"\n";
                    t.erase(s[si]);
                    si++;
                }
                // cout<<count<<"\n";
                
                si++;
                // cout<<"si: "<<si<<"\n";
                ei++;
                // cout<<"ei: "<<ei<<"\n";
                // if(t.find('w')!=t.end())
                    // cout<<"w found\n";
            }
            else{
                t.insert(s[ei++]);
                count++;
                // cout<<count<<"\n";
            }
        }
        res=max(res, count);
        return res;
    }
};