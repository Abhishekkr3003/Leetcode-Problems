class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& p) {
        sort(p.begin(),p.end(), [](auto &a, auto &b){
           return (a[0]==b[0]?a[1]<b[1]:a[0]>b[0]); 
        });
        set<int>st;
        int res=0;
        
        for(auto prop:p){
            if(st.upper_bound(prop[1])!=st.end()) res++;
            st.insert(prop[1]);
        }
        return res;
    }
};