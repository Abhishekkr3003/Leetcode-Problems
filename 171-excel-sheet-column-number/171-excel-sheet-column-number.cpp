class Solution {
public:
    int titleToNumber(string columnTitle) {
        int res=0;
        for(char ch:columnTitle){
            // cout<<ch-'A'<<endl;
            res=(1+(res*26)+(ch-'A'));
        }
        return res;
    }
};