class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(s.length()<=k) return false;
        
        unordered_set<int>st;
        int num=0;
        
        for(int i=0;i<k;i++){
            if(s[i]=='1') 
                num+=(1<<i);
        }
        
        st.insert(num);
        
        for(int i=k;i<s.length();i++){
            num>>=1;
            if(s[i]=='1') num+=(1<<(k-1));
            st.insert(num);
        }
        // cout<<(1<<(k-1));
        for(int i=0;i<(1<<(k));i++){
            if(st.find(i)==st.end()) return false;
        }
        
        return true;
    }
};