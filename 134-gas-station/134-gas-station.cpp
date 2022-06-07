class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalSum=0;
        int curSum=0;
        int index=-1;
        for(int i=0;i<cost.size();i++){
            cost[i]=gas[i]-cost[i];
            curSum+=cost[i];
            totalSum+=cost[i];
            if(curSum<0) {
                index=-1;
                curSum=0;
            }else{
                if(index==-1) index=i;
            }
        }
        return totalSum<0?-1:index;
    }
};