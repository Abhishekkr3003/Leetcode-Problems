class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        vector<int>t;
        while(x){
            t.push_back(x%10);
            x/=10;
        }
        int i=0, j=t.size()-1;
        while(i<j){
            if(t[i++]!=t[j--]) return false;
        }
        return true;
    }
};