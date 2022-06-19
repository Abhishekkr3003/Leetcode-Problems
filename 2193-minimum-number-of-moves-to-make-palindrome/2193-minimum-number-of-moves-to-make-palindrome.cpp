class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        int lo=0, hi=s.length()-1;
        
        int res=0;
        while(lo<hi){
            // cout<<lo<<" "<<hi<<endl;
            if(s[lo]=='.') {
                lo++;
                continue;
            }
            if(s[hi]=='.'){
                hi--;
                continue;
            }
            
            if(s[lo]==s[hi]) {
                lo++;
                hi--;
                continue;
            }
            
            int sameAsRight=0;
            int rightIndex=-1;
            for(int i=lo+1;i<hi;i++){
                if(s[i]!='.' && s[hi]!=s[i]){
                    sameAsRight++;
                }
                if(s[i]==s[hi]){
                    rightIndex=i;
                    break;
                }
            }
            
            int sameAsLeft=0;
            int leftIndex=-1;
            for(int i=hi-1;i>lo;i--){
                if(s[i]!='.' && s[lo]!=s[i]){
                    sameAsLeft++;
                }
                if(s[i]==s[lo]){
                    leftIndex=i;
                    break;
                }
            }
            if(leftIndex==-1 || sameAsRight<sameAsLeft){
                res+=sameAsRight+1;
                s[rightIndex]='.';
                hi--;
            }else{
                res+=sameAsLeft+1;
                s[leftIndex]='.';
                lo++;
            }
            // cout<<s<<endl;
            // cout<<res<<endl;
        }
        return res;
    }
};