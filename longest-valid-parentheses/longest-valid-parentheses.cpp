class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int>st;
        int res=0;
        int openCount=0;
        int closedIndex=-1;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(') {
                st.push(i);
                
            }
            else{
                if(st.empty()) closedIndex=i;
                else{
                    st.pop();
                    if(!st.empty())
                        res=max(res,i-max(closedIndex,st.top())); 
                    else
                        res=max(res,i-closedIndex);
                }
            }
        }
        return res;
    }
};