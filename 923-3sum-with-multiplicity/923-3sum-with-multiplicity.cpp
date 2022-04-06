class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        
        unordered_map<int,int>mp;
        for(int num:arr) mp[num]++;
        int mod=1e9+7;
        // cout<<mp[0]<<endl;
        if(target==0){
            long long n=mp[0];
            return (n*(n-1)*(n-2)/6)%mod;
        }
        vector<int>temp;
        for(auto p:mp) temp.push_back(p.first);
        sort(temp.begin(),temp.end());
        int res=0;
       
        for(int i=0;i<temp.size();i++){
            // cout<<i<<endl;
            int lo=i+1, hi=temp.size()-1;
            if(temp[i] && 3*temp[i]==target && mp[temp[i]]>=3){
                // cout<<"here1";
                int n=mp[temp[i]];
                res=(res+((long long)n*(n-1)*(n-2))/6)%mod;
            }
            if(mp[temp[i]]>=2 && target-2*temp[i]!=temp[i]) {
                if(mp.find(target-2*temp[i])!=mp.end()){
                    // cout<<"here2";
                    int n=mp[temp[i]];
                    res=(res+mp[target-2*temp[i]]*((long long)n*(n-1))/2)%mod;
                }
            }
            while(lo<hi){
                int sum=temp[i]+temp[lo]+temp[hi];
                if(sum==target) res=((long long)res+mp[temp[i]]*mp[temp[lo]]*mp[temp[hi--]])%mod;
                else if(sum<target) lo++;
                else hi--;
            }
            // cout<<res<<endl;
        }
        return res;
    }
};