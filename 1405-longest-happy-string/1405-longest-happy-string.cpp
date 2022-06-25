class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>>q;
        if(a!=0)q.push({a,'a'});
        if(b!=0)q.push({b,'b'});
        if(c!=0)q.push({c,'c'});
        
        string res="";
        
        while(!q.empty()){
            int count=q.top().first;
            char ch=q.top().second;
            q.pop();
            if(res.size()>=2 && res.back()==ch && res[res.length()-2]==ch){
                if(q.empty()) return res;
                int count2=q.top().first;
                char ch2=q.top().second;
                q.pop();
                res+=ch2;
                count2--;
                if(count2!=0) q.push({count2,ch2});
                q.push({count,ch});
                continue;
            }
            res+=ch;
            count--;
            if(count!=0) q.push({count,ch});    
        }
        return res;
        
    }
};