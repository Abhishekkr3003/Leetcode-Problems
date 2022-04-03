class Solution {
public:
    int candy(vector<int>& ratings) {
        if(ratings.size()==1) return 1;
        map<int,vector<int>>mp;
        for(int i=0;i<ratings.size();i++){
            mp[ratings[i]].push_back(i);
        }
        vector<int>t(ratings.size(),-1);
        for(auto p:mp){
            for(int i:p.second){
                if(i==0){
                    if(ratings[i+1]<ratings[i]) t[i]=t[i+1]+1;
                    else t[i]=1;
                }else if(i==ratings.size()-1){
                    if(ratings[i-1]<ratings[i]) t[i]=t[i-1]+1;
                    else t[i]=1;
                }else{
                    int maxCandy=0;
                    if(ratings[i]>ratings[i-1]) maxCandy=max(maxCandy,t[i-1]);
                    if(ratings[i]>ratings[i+1]) maxCandy=max(maxCandy,t[i+1]);
                    t[i]=maxCandy+1;
                }
            }
        }
        int res=0;
        for(int num:t) res+=num;
        return res;
    }
};