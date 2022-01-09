class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n=plantTime.size();
        priority_queue<pair<int,int>>q;
        for(int i=0;i<n;i++) q.push({growTime[i],i});
        int res=0;
        int lastPlantTime=-1;
        while(!q.empty()){
            auto p=q.top();
            q.pop();
            lastPlantTime+=(plantTime[p.second]);
            res=max(res,lastPlantTime+growTime[p.second]+1);
        }
        return res;
    }
};