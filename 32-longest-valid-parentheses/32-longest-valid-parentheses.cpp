/* 
    Time: O(n)
    Space: O(n)
    Tag: DP (Find the matching opening parentheses and check the length upto that opening parentheses and distance between current closing parentheses and matching opening paranthesis)
    Difficulty: MH
*/

class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.length();
        vector<int>t(n+1,0);
        stack<int>st;
        int res=0;
        for(int i=0;i<n;i++){
            if(s[i]=='(') st.push(i);
            else{
                if(!st.empty()){
                    int left=st.top();
                    st.pop();
                    t[i+1]=t[left]+i-left+1;
                }
            }
            res=max(res,t[i+1]);
        }
        return res;
    }
};