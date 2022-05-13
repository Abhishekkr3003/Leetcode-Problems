// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    long long int count(int coins[], int m, int n) {
        vector<vector<long long>> t(n + 1, vector<long long>(m+1));
        for (long long i = 0; i < n; i++) {
            t[i][0] = 0;
        }
        for (long long i = 0; i < m; i++) {
            t[0][i] = 1;
        }
        for (long long i = 1; i <= n; i++) {
            for (long long j = 1; j <= m; j++) {
                if (i < coins[j - 1])
                    t[i][j] = t[i][j - 1];
                else
                    t[i][j] = (t[i][j - 1] + t[i - coins[j - 1]][j]);
            }
        }
        return t[n][m];
        
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int arr[m];
        for (int i = 0; i < m; i++) cin >> arr[i];
        Solution ob;
        cout << ob.count(arr, m, n) << endl;
    }

    return 0;
}  // } Driver Code Ends