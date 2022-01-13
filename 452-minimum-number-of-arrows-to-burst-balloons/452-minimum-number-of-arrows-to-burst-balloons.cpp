class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int count=0;
        for(int i=0;i<points.size();i++){
            count++;
            int endLen=points[i][1];
            while(i+1<points.size() && points[i+1][0]<=endLen){
                i++;
                endLen=min(endLen,points[i][1]);
            }
        }
        return count;
    }
};