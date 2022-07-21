class Solution {
    vector<int> findLPS(string &pat){
        vector<int>lps(pat.length());
        int j=0;
        lps[0]=0;
        for(int i=1;i<pat.length();){
            if(pat[i]==pat[j]){
                lps[i]=j+1;
                i++, j++;
            }else{
                if(j==0){
                    lps[i]=0;
                    i++;
                }else{
                    j=lps[j-1];
                }
            }
        }
        return lps;
        
    }
public:
    int strStr(string haystack, string needle) {
        if(needle.empty()) return 0;
        
        vector<int>lps=findLPS(needle);
        
        int j=0;
        for(int i=0;i<haystack.length();){
            if(haystack[i]==needle[j]) {
                i++, j++;
            }else{
                if(j==0) i++;
                else j=lps[j-1];
            }
            if(j==needle.length()){
                return i-j;
            }
        }
        return -1;        
    }
};