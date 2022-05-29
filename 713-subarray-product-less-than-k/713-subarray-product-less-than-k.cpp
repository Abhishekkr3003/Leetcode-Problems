
/* 
    Time: O(n)
    Space: O(1)
    Tag: Two Poiters
    Difficulty: M 
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
    ll findSum(ll n){
        return (n*(n+1))/2;
    }

public:
    int numSubarrayProductLessThanK(vector<int> &inp, int k) {
        if(k==0) return 0;
        int n=inp.size();
        ll res=0;
        int start=0;
        ll curProd=1;
        for(int i=0;i<n;i++){
            // cout<<"i: "<<i<<endl;
            if(inp[i]>=k){
                res+=findSum(i-start);
                curProd=1;
                start=i+1;
                continue;
            }
            curProd*=inp[i];
            if(curProd>=k){
                int lastSub=i-start;
                res+=findSum(lastSub);
                int count=0;
                while(curProd>=k){
                    curProd/=inp[start++];
                    count++;
                }
                // cout<<count<<endl;
                res-=findSum(lastSub-count);
            }
            // cout<<"Res: "<<res<<endl;
        }
        res+=findSum(n-start);
        // cout<<res<<endl;
        return res;
    }
};