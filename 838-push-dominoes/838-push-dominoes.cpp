class Solution {
public:
    string pushDominoes(string d) {
        int n=d.length()+1;
        vector<int>left(n-1), right(n-1);
        string res="";
        
        if(d.back()=='L') left.back()=n;
        else left.back()=0;
        
        for(int i=d.length()-2;i>=0;i--){
            if(d[i]=='L') left[i]=n;
            else if(d[i]=='R') left[i]=0;
            else left[i]=max(0,left[i+1]-1);
        }
        
        if(d[0]=='R') right[0]=n;
        else right[0]=0;
        
        for(int i=1;i<d.length();i++){
            if(d[i]=='R') right[i]=n;
            else if(d[i]=='L') right[i]=0;
            else right[i]=max(0,right[i-1]-1);
        }
        
        for(int i=0;i<d.length();i++){
            if(left[i]==right[i]) res+='.';
            else if(left[i]<right[i]) res+='R';
            else res+='L';
        }
        return res;       
    }
};