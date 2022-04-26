/* 
    Time: O(N^2) || it needs a better description for sure. It's O(n ^ 2) because the total number of steps in the second loop and set intersection is n. When all points have a different x, set will include only one element (n * n * 1). If we have 2 points per x, it is n/2 * n/2 * 2. And so on...
    Space: O(N)
    Tag: Hashing, Maths, Geometry
    Difficulty: MH
*/

class Solution {
public:
    int minAreaRect(vector<vector<int>> &points) {
        unordered_map<int, int> xMapping;
        unordered_map<int, int> xReverseMapping;
        vector<unordered_set<int>> xWisePointsSet;
        vector<vector<int>> xWisePoints;
        for (vector<int> &point : points) {
            if (xMapping.find(point[0]) == xMapping.end()) {
                xMapping[point[0]] = xWisePoints.size();
                xReverseMapping[xWisePoints.size()] = point[0];
                xWisePoints.push_back({point[1]});
                xWisePointsSet.push_back({point[1]});
            } else {
                xWisePointsSet[xMapping[point[0]]].insert(point[1]);
                xWisePoints[xMapping[point[0]]].push_back(point[1]);
            }
        }
        int res = INT_MAX;
        for (int i = 0; i < xWisePoints.size(); i++) {
            if (xWisePoints[i].size() < 2) continue;
            for (int j = 0; j < xWisePoints[i].size(); j++) {
                for (int k = j + 1; k < xWisePoints[i].size(); k++) {
                    for (int x = i + 1; x < xWisePoints.size(); x++) {
                        if (xWisePointsSet[x].find(xWisePoints[i][j]) != xWisePointsSet[x].end() && xWisePointsSet[x].find(xWisePoints[i][k]) != xWisePointsSet[x].end()) {
                            res = min(res,abs(xWisePoints[i][j] - xWisePoints[i][k]) * abs(xReverseMapping[i] - xReverseMapping[x]));
                        }
                    }
                }
            }
        }
        return res==INT_MAX?0:res;
    }
};