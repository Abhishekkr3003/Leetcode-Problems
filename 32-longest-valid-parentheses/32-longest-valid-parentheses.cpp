class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int>st;
        vector<int>t(s.length()+1,0);
        t[0]=0;
        int res=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(') st.push(i);
            else {
                if(!st.empty()){
                    t[i+1]=i-st.top()+1+t[st.top()];
                    st.pop();
                    res=max(res,t[i+1]);
                }
            }
        }
        return res;
        
    }
};