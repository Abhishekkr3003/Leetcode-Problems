class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        sort(buildings.begin(),buildings.end(),[](vector<int>&a, vector<int>&b){
           if(a[0]==b[0]){
               return a[2]>b[2];
           } 
           else return a[0]<b[0];
        });
        vector<vector<int>>res;
        priority_queue<pair<int,int>>q;
        int i=0;
        while(i<buildings.size()){
            if(q.empty()) {
                res.push_back({buildings[i][0],buildings[i][2]});
                q.push({buildings[i][2],buildings[i][1]});
            }
            else if(buildings[i][0]>q.top().second){
                while(!q.empty() && buildings[i][0]>q.top().second){
                    pair<int,int>temp=q.top();
                    q.pop();
                    while(!q.empty() && q.top().second<=temp.second) q.pop();
                    if(q.empty()) res.push_back({temp.second,0});
                    else res.push_back({temp.second,q.top().first});
                }
                i--;
            }else{
                if(buildings[i][2]>q.top().first) {
                    res.push_back({buildings[i][0],buildings[i][2]});
                    q.push({buildings[i][2],buildings[i][1]});
                }else q.push({buildings[i][2],buildings[i][1]});
            }
            i++;
        }
        while(!q.empty()){
            pair<int,int>temp=q.top();
            q.pop();
            while(!q.empty() && q.top().second<=temp.second) q.pop();
            if(q.empty()) res.push_back({temp.second,0});
            else res.push_back({temp.second,q.top().first});
        }
        return res;
    }
};