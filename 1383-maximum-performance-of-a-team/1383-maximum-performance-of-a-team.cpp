#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
public:
    int maxPerformance(int n, vector<int> &speed, vector<int> &efficiency, int k) {
        vector<pair<int, int>> t;
        for (int i = 0; i < n; i++) {
            t.push_back({efficiency[i], speed[i]});
        }
        sort(t.rbegin(), t.rend());
        long sum = 0;
        long mod = 1000000007;
        long res = 0;
        priority_queue<int, vector<int>, greater<int>> heap;
        for (pair<int, int> p : t) {
            sum =(sum+ p.second);
            heap.push(p.second);
            if (heap.size() > k) {
                sum -= heap.top();
                heap.pop();
            }
            res = max(res, (sum * p.first));
        }
        return res%mod;
    }
};