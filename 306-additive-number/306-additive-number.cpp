class Solution {
    
    bool findSol(int lastIdx, string &num, long long f, long long s){
        if(lastIdx==num.length()-1) return true;
        
        string sum=to_string(f+s);
        
        if(lastIdx+sum.length()<num.length() && num.substr(lastIdx+1,sum.length())==sum){
            long long temp=f;
            f=s;
            s+=temp;
            if(findSol(lastIdx+sum.length(),num,f,s)) return true;
        }
        
        return false;      
    }
    
public:
    bool isAdditiveNumber(string num) {
        for(int i=1;i<=min(18,(int)num.length()-2);i++){
            for(int j=1;i+j<=min(18,(int)num.length()-1);j++){
                if((num[0]=='0' && i>1) || (num[i]=='0' && j>1)) continue;
                long long f=stoll(num.substr(0,i));
                long long s=stoll(num.substr(i,j));
                cout<<f<<" "<<s<<endl;
                if(findSol(i+j-1,num,f,s)) return true;
            }
        }
        return false;
    }
};