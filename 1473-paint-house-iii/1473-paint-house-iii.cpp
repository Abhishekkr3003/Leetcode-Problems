class Solution {
    vector<int>houses;
    vector<vector<int>>costs;
    vector<vector<vector<int>>>t;
    int n, target;
    
    long long solve(int m, int nbr, int prev){
        // cout<<m<<endl;
        if(nbr>target) return INT_MAX;
        if(m==houses.size()){
            if(target==nbr) return 0;
            return INT_MAX-1;
        }
        
        if(t[m][nbr][prev]!=-1) return t[m][nbr][prev];
        
        long long res=INT_MAX;
        if(houses[m]!=0){
            if(prev==houses[m]) res=min(res,solve(m+1,nbr,houses[m]));
            else res=min(res,solve(m+1,nbr+1,houses[m]));
        }else{
            for(int i=0;i<n;i++){
                if(prev==i+1) res=min(res, (long long)costs[m][i]+solve(m+1,nbr,i+1));
                else res=min(res,(long long)costs[m][i]+solve(m+1,nbr+1,i+1));
            }
        }
        // cout<<res<<endl;
        return t[m][nbr][prev]=res;
    }
    
    
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        this->houses=houses;
        this->costs=cost;
        this->n=n;
        this->target=target;
        t.resize(m+1,vector<vector<int>>(target+1, vector<int>(n+1,-1)));
        int res= solve(0,0,0);   
        if(res==INT_MAX) return -1;
        return res;
    }
};