class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<char>st;
        vector<pair<int,int>>t(26,{0,false});
        for(char ch:s){
            t[ch-'a'].first++;
        }
        for(char ch:s){
            // cout<<ch<<endl;
            if(t[ch-'a'].second) {
                t[ch-'a'].first--;
                // cout<<ch<<" "<<st.top()<<" "<<st.size()<<endl;
                continue;
            }
            // cout<<t[3].first<<endl;
            while(!st.empty() && st.top()>ch && t[st.top()-'a'].first>=1) {
                t[st.top()-'a'].second=false;
                st.pop();
            }
            st.push(ch);
            t[ch-'a'].second=true;
            t[ch-'a'].first--;
            // cout<<ch<<" "<<st.top()<<" "<<st.size()<<endl;
            
        }
        // cout<<"here";
        string res="";
        while(!st.empty()){
            if(t[st.top()-'a'].second){
                res=res+st.top();
                t[st.top()-'a'].second=false;
            }
            // cout<<st.top()<<endl;
            st.pop();
            
        }
        reverse(res.begin(),res.end());
        return res;
    }
};