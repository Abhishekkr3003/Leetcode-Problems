class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.length()+s2.length()!=s3.length()) return false;
        vector<bool>t(s2.length()+1);
        vector<bool>temp(s2.length()+1);
        t[0]=true;
        for(int i=0;i<s2.length();i++){
            t[i+1]=(t[i] && s2[i]==s3[i]);
        }
        
        // cout<<t.size()<<endl;
        for(int i=1;i<=s1.length();i++){
            // for(int k=0;k<t.size();k++) cout<<t[k]<<" ";
            // cout<<endl;
            temp.clear();
            temp.resize(s2.length()+1);
            temp[0]=(t[0] && (s1[i-1]==s3[i-1]));
            for(int j=1;j<=s2.length();j++){
                temp[j]=((temp[j-1] && s2[j-1]==s3[i+j-1]) || (t[j] && s1[i-1]==s3[i+j-1]));
            }
            t=temp;
        }
        // for(int i=0;i<t.size();i++) cout<<t[i]<<" ";
        return t[s2.length()];
    }
};