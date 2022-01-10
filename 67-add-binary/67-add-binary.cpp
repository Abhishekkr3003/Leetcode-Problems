class Solution {
public:
    string addBinary(string a, string b) {
        bool carry=false;
        int i=a.length()-1;
        int j=b.length()-1;
        string res;
        while(i>=0 && j>=0){
            bool bit=(a[i]-'0')^(b[j]-'0')^carry;
            carry=(a[i]-'0' && b[j]-'0') || (a[i]-'0' && carry) || (b[j]-'0' && carry);
            res+=bit?'1':'0';  
            i--,j--;
        }
        while(i>=0){
            bool bit=(a[i]-'0')^carry;
            carry=(a[i]-'0' && carry);
            res+=bit?'1':'0';   
            i--;
        }
        while(j>=0){
            bool bit=(b[j]-'0')^carry;
            carry=(b[j]-'0' && carry);
            res+=bit?'1':'0';   
            j--;
        }
        if(carry) res+='1';
        reverse(res.begin(),res.end());
        return res;
    }
};