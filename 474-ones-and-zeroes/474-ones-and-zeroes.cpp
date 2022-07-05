class Solution {
    vector<vector<vector<int>>>t;
    
    int solve(vector<pair<int,int>>& strs, int m, int n, int idx){
        if(idx==strs.size()) return 0;
        
        if(t[m][n][idx]!=-1) return t[m][n][idx];
        
        int res=solve(strs,m,n,idx+1);
        
        if(m>=strs[idx].first && n>=strs[idx].second){
            res=max(res,1+solve(strs,m-strs[idx].first, n-strs[idx].second,idx+1));
        }
        
        return t[m][n][idx]=res;
        
    }
    
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        t.resize(m+1,vector<vector<int>>(n+1, vector<int>(strs.size(),-1)));
        
        vector<pair<int,int>>temp(strs.size());
        
        for(int i=0;i<strs.size();i++){
            int freq=0;
            for(char ch:strs[i]){
                if(ch=='0') freq++;
            }
            temp[i]={freq, strs[i].length()-freq};
        }
        // for(auto p:temp) cout<<p.first<<" "<<p.second<<endl;
        return solve(temp,m,n,0);
    }
};