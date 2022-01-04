class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int>NSL(n);
        vector<int>subMinSum(n);
        int mod=1e9+7;
        stack<pair<int,int>>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && st.top().first>=arr[i]) st.pop();
            if(st.empty()) NSL[i]=-1;
            else NSL[i]=st.top().second;
            st.push({arr[i],i});
        }
        for(int i=0;i<n;i++){
            subMinSum[i]=((i-NSL[i])*arr[i])%mod;
            if(NSL[i]!=-1) subMinSum[i]=(subMinSum[i]+subMinSum[NSL[i]])%mod;
        }
        int res=0;
        for(int num:subMinSum) res=(res+num)%mod;
        return res;              
    }
};