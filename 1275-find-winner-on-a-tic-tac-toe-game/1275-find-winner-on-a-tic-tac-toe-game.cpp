// Better Solution: https://leetcode.com/problems/find-winner-on-a-tic-tac-toe-game/discuss/441319/JavaPython-3-Check-rows-columns-and-two-diagonals-w-brief-explanation-and-analysis. 

class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        vector<int>brd1(9,false), brd2(9,false);
        for(int i=0;i<moves.size();i++){
            if((i&1)==0) brd1[moves[i][0]*3+moves[i][1]]=true;
            else brd2[moves[i][0]*3+moves[i][1]]=true;
        }
        if((brd1[0]+brd1[3]+brd1[6]==3) || (brd1[1]+brd1[4]+brd1[7]==3) || (brd1[2]+brd1[5]+brd1[8]==3) || (brd1[0]+brd1[1]+brd1[2]==3) || (brd1[3]+brd1[4]+brd1[5]==3) || (brd1[6]+brd1[7]+brd1[8]==3) || (brd1[0]+brd1[4]+brd1[8]==3) || (brd1[2]+brd1[4]+brd1[6]==3)) return "A";
        if((brd2[0]+brd2[3]+brd2[6]==3) || (brd2[1]+brd2[4]+brd2[7]==3) || (brd2[2]+brd2[5]+brd2[8]==3) || (brd2[0]+brd2[1]+brd2[2]==3) || (brd2[3]+brd2[4]+brd2[5]==3) || (brd2[6]+brd2[7]+brd2[8]==3) || (brd2[0]+brd2[4]+brd2[8]==3) || (brd2[2]+brd2[4]+brd2[6]==3)) return "B";
        if(moves.size()==9) return "Draw";
        return "Pending";
    }
};