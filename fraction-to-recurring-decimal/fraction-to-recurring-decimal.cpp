class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        int sign=1;
        if(numerator<0) sign *=-1;
        if(denominator<0) sign*=-1;
        numerator=abs(numerator);
        denominator=abs(denominator);
        long q=numerator/denominator;
        long r=numerator%denominator;
        if(r==0) return sign==-1?to_string(-q):to_string(q);
        vector<int>temp;
        // cout<<sign<<endl;
        string res=sign==-1?"-"+to_string(q):to_string(q);
        res+='.';
        unordered_map<int,int>mp;
        while(r!=0){
            mp[r]=temp.size();
            q=(r*10)/denominator;
            r=(r*10)%denominator;
            if(mp.find(r)!=mp.end()){
                int i=0;
                while(i<mp[r]) res+=to_string(temp[i++]);
                res+="(";
                while(i<temp.size()) res+=to_string(temp[i++]);
                res+=to_string(q);
                res+=")";
                return res;
            }
            temp.push_back(q);
            
        }
        for(int num:temp) res+=to_string(num);
        return res;
        
    }
};