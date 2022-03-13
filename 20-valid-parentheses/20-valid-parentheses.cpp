class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(char ch:s){
            if(ch=='(' || ch=='{' || ch=='[') st.push(ch);
            else{
                if(st.empty() ||( st.top()+1!=ch && st.top()+2!=ch)) return false;
                st.pop();
            }
        }
        return st.empty();
    }
};