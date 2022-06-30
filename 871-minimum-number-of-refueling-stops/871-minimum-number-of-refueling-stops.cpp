class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int>q;
        sort(stations.begin(),stations.end());
        
        int curLoc=startFuel;
        int res=0;
        int pos=0;
        int n=stations.size();
        
        while(curLoc<target){
            while(pos<n && stations[pos][0]<=curLoc){
                q.push(stations[pos][1]);
                pos++;
            }
            if(q.empty()) return -1;
            curLoc+=q.top();
            res++;
            q.pop();
        }
        return res;
    }
};