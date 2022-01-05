class Solution {
    bool isPalindrome(string str){
        int i=0, j=str.length()-1;
        while(i<j) if(str[i++]!=str[j--]) return false;
        return true;
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>>t[s.length()+1];
        for(int i=1;i<=s.length();i++){
            for(int j=1;j<=i;j++){
                string temp=s.substr(j-1,i-j+1);
                if(isPalindrome(temp)){
                    // cout<<j-1<<endl;
                    if((j-1)==0) t[i].push_back({temp});
                    else{
                        for(auto v:t[j-1]) {
                            v.push_back(temp);
                            t[i].push_back(v);
                            v.pop_back();
                        }
                    }
                }
            }
            
        }
        return t[s.length()];
    }
};