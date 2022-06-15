class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        
        int n=profit.size();
        vector<vector<int>>jobs(n);
        for(int i=0;i<n;i++){
            jobs[i]={startTime[i],endTime[i],profit[i]};
        }
        
        sort(jobs.begin(),jobs.end(), [](auto& a, auto& b){
            if(a[1]!=b[1]) return a[1]<b[1];
            if(a[0]!=b[0]) return a[0]<b[0];
            return a[2]<b[2];
        });
        
        vector<pair<int,int>>t;
        
        for(int i=0;i<n;i++){
            if(t.empty()) {
                t.push_back({jobs[i][1],jobs[i][2]});
                continue;
            }
            
            int startIdx=upper_bound(t.begin(),t.end(),make_pair(jobs[i][0],INT_MAX))-t.begin();
            int extra=0;
            if(startIdx!=0) extra=t[startIdx-1].second;
            // cout<<startIdx<<endl;
            if(t.back().first==jobs[i][1]) t.back().second=max(t.back().second,jobs[i][2]+extra);
            else if(t.back().second<jobs[i][2]+extra) t.push_back({jobs[i][1],jobs[i][2]+extra});
                        
        }
        
        int res=0;
        for(auto temp:t) {
            // cout<<temp.first<<" "<<temp.second<<endl;
            res=max(res,temp.second);
        }
        return res;            
    }
};