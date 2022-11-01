/* 
    Time: O()
    Space: O()
    Tag: 
    Difficulty: 
*/

class Solution {
    vector<int> sessions;
    map<string, int> t;
    int sessionTime;
    vector<int> tasks;

    string makeKey(int idx) {
        vector<int>temp=sessions;
        sort(temp.begin(),temp.end());
        string res = to_string(idx);
        for (int i = 0; i < sessions.size(); i++) {
            res += "$" + to_string(temp[i]);
        }
        return res;
    }

    int solve(int idx) {
        if (idx == tasks.size()) return 0;
        string key = makeKey(idx);

        if (t.find(key) != t.end()) return t[key];

        sessions.push_back(tasks[idx]);
        int res = 1 + solve(idx + 1);
        sessions.pop_back();

        for (int i = 0; i < sessions.size(); i++) {
            if (sessions[i] + tasks[idx] <= sessionTime) {
                sessions[i] += tasks[idx];
                res = min(res, solve(idx + 1));
                sessions[i] -= tasks[idx];
            }
        }
        return t[key]=res;
    }

public:
    int minSessions(vector<int> &tasks, int sessionTime) {
        this->sessionTime = sessionTime;
        this->tasks = tasks;
        return solve(0);
    }
};