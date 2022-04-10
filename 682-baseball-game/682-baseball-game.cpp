class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int>st;
        int f,s;
        for(int i=0;i<ops.size();i++){
            if(ops[i]=="C") st.pop();
            else if(ops[i]=="+") {
                f=st.top(); st.pop();
                s=st.top(); st.push(f);
                st.push(f+s);
            }else if(ops[i]=="D") st.push(st.top()*2);
            else st.push(stoi(ops[i]));
        }
        int res=0;
        while(!st.empty()) { res+=st.top(); st.pop(); }
        return res;
    }
};