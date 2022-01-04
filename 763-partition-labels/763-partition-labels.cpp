class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int>lastPos(26,-1);
        for(int i=s.length()-1;i>=0;i--){
            if(lastPos[s[i]-'a']==-1) lastPos[s[i]-'a']=i;
        }
        vector<int>res;
        int start=0;
        int partitionEnd=lastPos[s[0]-'a'];
        for(int i=0;i<s.length();i++){
            partitionEnd=max(partitionEnd, lastPos[s[i]-'a']);
            if(i==partitionEnd) {
                res.push_back(i+1-start);
                start=i+1;
            }
        }
        
        return res;
    }
};