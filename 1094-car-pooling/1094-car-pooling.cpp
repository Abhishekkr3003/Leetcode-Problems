class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int>city(1001,0);
        for(auto v:trips){
            city[v[1]]+=v[0];
            city[v[2]]-=v[0];
        }
        int curOccupancy=0;
        for(int i=0;i<=1000;i++){
            curOccupancy+=city[i];
            if(curOccupancy>capacity) return false;
        }
        return true;
    }
};


