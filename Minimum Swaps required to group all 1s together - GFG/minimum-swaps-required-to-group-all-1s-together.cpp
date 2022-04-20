// { Driver Code Starts
// C++ program to find minimum swaps
// required to group all 1's together
#include <bits/stdc++.h>

using namespace std;

// Function to find minimum swaps
// to group all 1's together
int minSwaps(int arr[], int n) ;


// Driver Code
int main() {
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        
        cout << minSwaps(a, n)<<endl;
    
    }

    return 0;
}
// } Driver Code Ends


int minSwaps(int arr[], int n) {
    
    int ones=0;
    for(int i=0;i<n;i++) if(arr[i]) ones++;
    if(ones==0) return -1;
    int res=0;
    int curOnes=0;
    int i=0;
    for(;i<ones;i++){
        if(arr[i]) curOnes++;
    }
    res=ones-curOnes;
    for(;i<n;i++){
        if(arr[i-ones]) curOnes--;
        if(arr[i]) curOnes++;
        res=min(res,ones-curOnes);
    }
    return res;
}