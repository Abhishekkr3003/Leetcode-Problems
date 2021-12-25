class Solution {
    int pos;
    string s;
    int getNum(){
        int num=0;
        skipSpaces();
        while(pos<s.length() && isdigit(s[pos])){
            num*=10;
            num+=s[pos]-'0';
            pos++;
        }
        skipSpaces();
        return num;
    }
    
    int solve(int num1, int num2, char operator_){
        if(operator_=='+') return num1+num2;
        else if(operator_=='-') return num1-num2;
        else if(operator_=='*') return num1*num2;
        else return num1/num2;
    }
    void skipSpaces(){
        while(isspace(s[pos]))pos++;
    }
    
public:
    int calculate(string s) {
        this->s=s;
        unordered_map<char,int>priority={{'+',1},{'-',1},{'*',2},{'/',2}};
        stack<int>stInt;
        stack<char>stChar;
        pos=0;
        char symbol;
        stInt.push(getNum());
        if(pos>=s.length()) return stInt.top();
        stChar.push(s[pos++]);
        stInt.push(getNum());
        while(pos<s.length()){
            symbol=s[pos++];
            while(!stChar.empty() && priority[symbol]<=priority[stChar.top()]){
                int num2=stInt.top(); stInt.pop();
                int num1=stInt.top(); stInt.pop();
                char operation_=stChar.top(); stChar.pop();
                stInt.push(solve(num1, num2, operation_));
            }
            stChar.push(symbol);
            stInt.push(getNum());  
        }
        while(!stChar.empty()){
            int num2=stInt.top(); stInt.pop();
            int num1=stInt.top(); stInt.pop();
            char operation_=stChar.top(); stChar.pop();
            stInt.push(solve(num1, num2, operation_));
        }
        return stInt.top();     
    }
};