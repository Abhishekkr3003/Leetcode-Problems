/*
    Time: O(n)
    Space: O(n)
    Tag: Typical String Algorithm (Z funtion Algorithm (https://www.youtube.com/watch?v=CpZh4eF8QBw))
    Difficulty: H
*/

typedef long long ll;

class Solution {
public:
    long long sumScores(string s) {
        ll res=s.length();
        vector<int>t(s.length());
        t[0]=0;
        int left=0, right=0;
        for(int i=1;i<s.length();i++){
            if(i>right){
                left=right=i;
                while(right<s.length() && s[right]==s[right-left]) right++;
                t[i]=right-left;
                right--;
            }else{
                if(t[i-left]+i<=right){
                    t[i]=t[i-left];
                }else{
                    left=i;
                    while(right<s.length() && s[right]==s[right-left]) right++;
                    t[i]=right-left;
                    right--;
                }
            }
            res+=t[i];
        }
        return res;
    }
};