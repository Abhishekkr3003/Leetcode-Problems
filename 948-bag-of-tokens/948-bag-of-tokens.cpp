class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        
        int i=0, j=tokens.size()-1;
        int res=0;
        int score=0;
        
        while(i<=j) {
            if(power>=tokens[i]) {
                score++;
                res=max(res,score);
                power-=tokens[i];
                i++;
            }else if(score>0){
                score--;
                power+=tokens[j];
                j--;
            }else break;
        }
        return res;
    }
};