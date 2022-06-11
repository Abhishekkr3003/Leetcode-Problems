class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hDegree=(hour%12)*30.0+(30.0*minutes/60.0);
        double mDegree=6*minutes;
        
        double deg= abs(hDegree-mDegree);
        if(deg<=180) return deg;
        return 360-deg;
    }
};