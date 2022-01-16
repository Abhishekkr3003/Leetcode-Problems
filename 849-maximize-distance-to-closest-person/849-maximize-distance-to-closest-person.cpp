class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int lastOne=0;
        int i=0;
        int res=0;
        while(i<seats.size() && !seats[i]) i++;
        res=i;
        lastOne=i;
        for(;i<seats.size();i++){
            if(seats[i]) {
                res=max(res,(i-lastOne)/2);
                lastOne=i;
            }
        }
        res=max(res,i-lastOne-1);
        return res;        
    }
};