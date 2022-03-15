// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += arr[i];
        }
        int tempSum = sum;
        sum /= 2;
        vector<bool> t(sum + 1, 0);
        vector<bool> temp(sum + 1);
        t[0] = 1;
        temp[0]=1;
        // cout<<sum<<endl;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= sum; j++) {
                if (arr[i] > j)
                    temp[j] = t[j];
                else
                    temp[j] = t[j - arr[i]] || t[j];
            }
            // for(int num:t) cout<<num<<" ";
            // cout<<endl;
            t = temp;
        }
        // for(int num:t) cout<<num<<" ";
        // cout<<endl;
        for (int i = sum; i >= 0;i--){
            if(t[i]){
                return tempSum - (2 * i);
            }
        }
        return 0;
	} 
};


// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends