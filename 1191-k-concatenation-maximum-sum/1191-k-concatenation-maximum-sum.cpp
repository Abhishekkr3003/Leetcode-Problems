typedef long long ll;

class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        
        ll maxi=0;
        ll curMaxi=0;
        ll mod=1e9+7;
        
        int n=arr.size();
        ll sum=0;
        
        ll maxFromLeft=0;
        ll maxFromRight=0;
        
        for(int i=0;i<n;i++){
            sum=(sum+arr[i]);
            maxFromLeft=max(maxFromLeft,sum);
            curMaxi=(curMaxi+arr[i]);
            maxi=max(maxi,curMaxi);
            if(curMaxi<0) curMaxi=0;
        }      
        
        if(k==1) return maxi;
        sum=0;
        
        for(int i=n-1;i>=0;i--){
            sum=(sum+arr[i]);
            maxFromRight=max(maxFromRight,sum);
        }
        cout<<maxi<<endl;
        cout<<((maxFromRight)+(maxFromLeft)+(k-2)*sum)%mod;
        return max({maxi,((maxFromRight)+(maxFromLeft)+(k-2)*sum),(maxFromRight)+(maxFromLeft)})%mod;
        
    }
};