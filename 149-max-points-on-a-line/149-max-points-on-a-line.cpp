// Better Solution in Solution

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        if(points.size()<3) return points.size();
        map<pair<double,double>,set<pair<int,int>>>mp;
        int res=0;
        for(int i=0;i<points.size();i++){
            for(int j=0;j<i;j++){
                auto p1=points[i];
                auto p2=points[j];
                if(p1[0]==p2[0]){
                    mp[{INT_MAX,p1[0]}].insert({p1[0],p1[1]});
                    mp[{INT_MAX,p1[0]}].insert({p2[0],p2[1]});
                    res=max(res,(int)mp[{INT_MAX,p1[0]}].size());
                }else{
                    double slope=(p1[1]-p2[1])/(double)(p1[0]-p2[0]);
                    double intercept=p1[1]-(slope*p1[0]);
                    mp[{slope,intercept}].insert({p1[0],p1[1]});
                    mp[{slope,intercept}].insert({p2[0],p2[1]});
                    res=max(res,(int)mp[{slope,intercept}].size());
                }
            }
        }
        return res;
    }
};