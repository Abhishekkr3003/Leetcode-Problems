class Solution {
    vector<vector<int>>t;
    string s1, s2,s3;
    
    bool solve(int i, int j){
        // cout<<i<<" "<<j<<endl;
        if(i+j==s3.length()) return true;
        if(t[i][j]!=-1) return t[i][j];
        
        int k=i+j;
        if(i<s1.length() && s1[i]==s3[k]){
            if(solve(i+1,j)) return true;
        }
        if(j<s2.length() && s2[j]==s3[k]){
            if(solve(i,j+1)) return true;
        }
        return t[i][j]=false;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.length()+s2.length()!=s3.length()) return false;
        this->s1=s1, this->s2=s2, this->s3=s3;
        t.resize(s1.length()+1, vector<int>(s2.length()+1,-1));
        return solve(0, 0);
    }
};