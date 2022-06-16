class Solution {
public:
    long long appealSum(string s) {
        vector<int>lastPos(26,0);
        long long repeated=0, res=0;
        
        for(long long i=0;i<s.length();i++){
            repeated+=lastPos[s[i]-'a'];
            lastPos[s[i]-'a']=i+1;
            res+=((i+1)*(i+2))/2-repeated;
        }
        return res;
    }
};