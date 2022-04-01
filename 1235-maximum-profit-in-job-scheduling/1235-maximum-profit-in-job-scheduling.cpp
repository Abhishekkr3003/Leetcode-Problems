class Solution {
    vector<int> t;
    vector<vector<int>>process;
    vector<int>startTime;

    int solve(int index) {
        if (index >= startTime.size()) return 0;
        if (t[index] != -1) return t[index];
        int res = 0;
        res = solve(index + 1);
        int next = lower_bound(startTime.begin(), startTime.end(), process[index][1]) - startTime.begin();
        res = max(res, process[index][2]+solve(next));
        return t[index] = res;
    }

public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        t.resize(startTime.size() + 1, -1);
        for (int i = 0; i < startTime.size(); i++)
            process.push_back({ startTime[i],endTime[i],profit[i] });

        sort(process.begin(), process.end());
        sort(startTime.begin(), startTime.end());
        for (int i = 0; i < startTime.size(); i++) this->startTime.push_back(process[i][0]);
        return solve(0);
    }
};