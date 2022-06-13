class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int toptop=0, topbottom=0, bottomtop=0, bottombottom=0;
        
        int n=tops.size();
        
        for(int i=0;i<n;i++){
            if(tops[i]!=tops[0] && bottoms[i]!=tops[0]) toptop=topbottom=-1;
            if(tops[i]!=bottoms[0] && bottoms[i]!=bottoms[0]) bottomtop=bottombottom=-1;
            
            if(toptop!=-1){
                if(tops[0]==tops[i]) toptop++;
                if(tops[0]==bottoms[i]) topbottom++;
            }
            if(bottombottom!=-1){
                if(bottoms[0]==tops[i]) bottomtop++;
                if(bottoms[0]==bottoms[i]) bottombottom++;
            }
        }
        if(toptop==-1 && bottombottom==-1) return -1;
        return min({n-toptop, n-topbottom, n-bottomtop, n-bottombottom});        
    }
};