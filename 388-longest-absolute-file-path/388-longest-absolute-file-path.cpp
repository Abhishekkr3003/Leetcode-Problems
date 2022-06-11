class Solution {

    
public:
    int lengthLongestPath(string input) {
        
        stack<int>st;
        int res=0;
        int n=input.length();
        int i=0;
        int depth=0;
        int len=0;
        
        while(i<n){
            depth=0;
            len=0;
            bool isFile=false;
            
            while(i<n && input[i]=='\t') {
                depth++;
                i++;
            }
            while(i<n && input[i]!='\n') {
                len++;
                if(input[i]=='.') isFile=true;
                i++;
            }
            i++;      
            while(st.size()>depth) st.pop();
            
            if(st.empty()) st.push(len);
            else st.push(len+st.top());
            // cout<<st.top()<<endl;
            
            if(isFile) res=max(res,st.top()+(int)st.size()-1);            
            
        }
        return res;
        
    }
};