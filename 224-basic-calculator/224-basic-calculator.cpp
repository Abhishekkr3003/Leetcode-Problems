class Solution {
    
    int eval(int num1, int num2, char sym){
        // cout<<num1<<" "<<num2<<" "<<sym;
        if(sym=='+') return num1+num2;
        return num1-num2;
    }
    
    int solve(string &s, int &idx){
        int res=0;
        int curNum=0;
        bool subtr=false;
        char curSym='+';
        while(s[idx]==' ') idx++;
        if(s[idx]=='-'){
            idx++;
            subtr=true;
        } 
        // cout<<res<<endl;
        // cout<<idx<<endl;
        while(idx<s.length()){
            if(s[idx]=='('){
                idx++;
                curNum=solve(s,idx);
                if(subtr){
                    subtr=false;
                    curNum=-curNum;
                }
                res=eval(res,curNum,curSym);
            }else if(s[idx]==')'){
                idx++;
                return res;
            }else if(isdigit(s[idx])){
                int start=idx;
                while(idx<s.length() && isdigit(s[idx])){
                    idx++;
                }
                curNum=stoi(s.substr(start,idx-start));
                if(subtr){
                    subtr=false;
                    curNum=-curNum;
                }
                res=eval(res,curNum,curSym);
            }else if(isspace(s[idx])) idx++;
            else curSym=s[idx++];
        }
        return res;
    }
    
public:
    int calculate(string s) {
        int idx=0;
        return solve(s,idx);
    }
};