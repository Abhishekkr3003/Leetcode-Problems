#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
    vector<int> rank;
    vector<int> parent;
    int mst = 0;
    int find(int a) {
        if (parent[a] == -1)
            return a;
        else
            return parent[a] = find(parent[a]);
    }
    void union_(int a, int b, int wt) {
        // cout << a << " " << b << " " << wt << endl;
        int s1 = find(a);
        int s2 = find(b);
        if (s1 == s2)
            return;
        if (rank[s1] < rank[s2]) {
            parent[s1] = s2;
            rank[s2] += rank[s1];
        } else {
            parent[s2] = s1;
            rank[s1] += rank[s2];
        }
        mst += wt;
    }

public:
    int minCostConnectPoints(vector<vector<int>> &points) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> minHeap;
        parent.resize(points.size(), -1);
        rank.resize(points.size(), 1);
        int dist = 0;
        for (int i = 0; i < points.size() - 1; i++) {
            for (int j = i + 1; j < points.size(); j++) {
                dist = abs(points[j][0] - points[i][0]) + abs(points[j][1] - points[i][1]);
                minHeap.push({dist, {i, j}});
            }
        }
        while (!minHeap.empty()) {
            union_(minHeap.top().second.first, minHeap.top().second.second, minHeap.top().first);
            minHeap.pop();
        }
        return mst;
    }
};