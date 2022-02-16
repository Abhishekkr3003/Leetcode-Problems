// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	    if(n==1) return arr[0];
	    if(n==2) return max(arr[0],arr[1]);
	    if(n==3) return max(arr[0]+arr[2], arr[1]);
	    int f=arr[0], s=arr[1], t=arr[2]+arr[0];
	    int res=max(arr[0]+arr[2],arr[1]);
	    for(int i=3;i<n;i++){
	        int temp=arr[i]+max(f,s);
	        f=s;
	        s=t;
	        t=temp;
	        res=max(res,temp);
	       // cout<<res<<endl;
	    }
	    return res;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends