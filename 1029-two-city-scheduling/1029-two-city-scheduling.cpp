/*
    Time: O(nlogn)
    Space: O(n)
    Tag: Greedy, Sorting
    Difficulty: M
*/

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int sum = 0;
        for (int i = 0; i < costs.size(); i++) {
            sum += costs[i][1];
        }
        vector<int> temp;
        for (int i = 0; i < costs.size(); i++) {
            temp.push_back(costs[i][0] - costs[i][1]);
        }
        sort(temp.begin(), temp.end());
        int sum2 = 0;
        for (int i = 0; i < costs.size() / 2; i++) {
            sum2 += temp[i];
        }
        return sum + sum2;
    }
};