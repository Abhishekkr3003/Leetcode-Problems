class Solution {
public:
    string removeKdigits(string num, int k) {
        int i=1;
        // cout<<num.length()<<endl;
        string res="";
        res+=num[0];
        for(;i<num.length();i++){
            if(num[i]<res.back()){
                // cout<<"i: "<<i<<endl;
                // cout<<"fdaj: "<<res.back()<<endl;
                res.pop_back();
                i--;
                k--;
                // cout<<k<<endl;
                if(k==0) break;
            }else {
                res.push_back(num[i]);
            }
        }
        i++;
        for(;i<num.length();i++){
            res.push_back(num[i]);
        }
        while(k>0 && res.length()>0) {
            res.pop_back();
            k--;
        }
        i=0;
        while(res[i]=='0') i++;
        res= res.substr(i,res.length()-i);
        if(res=="") return "0";
        return res;
    }
};