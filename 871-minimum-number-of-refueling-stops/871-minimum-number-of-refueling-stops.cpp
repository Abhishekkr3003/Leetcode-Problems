class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>> &stations) {
        if (target <= startFuel) return 0;
        priority_queue<int> pq;
        pq.push(startFuel);

        int pos = 0;
        int idx = 0;
        int res = -1;
        while (pos < target) {
            while (idx < stations.size() && stations[idx][0] <= pos) {
                pq.push(stations[idx++][1]);
            }
            if (pq.empty()) return -1;
            pos += pq.top();
            pq.pop();
            res++;
        }
        return res;
    }
};