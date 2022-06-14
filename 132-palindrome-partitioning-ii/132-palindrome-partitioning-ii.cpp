class Solution {
public:
    int minCut(string s) {
        int n=s.length();
        vector<int>t(n);
        
        for(int i=0;i<n;i++) t[i]=i;
        
        for(int i=0;i<n;i++){
            
            for(int j=0;j<n && i-j>=0 && j+i<n;j++){
                if(s[i-j]==s[j+i]) {
                    if(i==j) t[i+j]=0;
                    else t[j+i]=min(t[j+i],t[i-j-1]+1);
                }
                else break;
            }
            
            for(int j=0;j<n && i-j>=0 && j+i+1<n;j++){
                if(s[i-j]==s[j+i+1]) {
                    if(i==j) t[i+j+1]=0;
                    else t[j+i+1]=min(t[j+i+1],t[i-j-1]+1);
                }
                else break;
            }
            
        }
        // for(int num:t) cout<<num<<endl;
        return t[n-1];
    }
};