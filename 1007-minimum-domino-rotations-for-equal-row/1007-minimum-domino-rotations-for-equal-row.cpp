/* 
    Time: O(n)
    Space: O(1)
    Tag: Arrays
    Difficulty: M
*/

class Solution {
public:
    int minDominoRotations(vector<int> &tops, vector<int> &bottoms) {
        int curSwapsTop = 0, curSwapsBot = 0, minSwaps = INT_MAX;
        for (int i = 1; i <= 6; i++) {
            curSwapsTop = 0;
            curSwapsBot = 0;
            for (int j = 0; j < tops.size(); j++) {
                if (tops[j] == i && bottoms[j] == i)
                    continue;
                else if (tops[j] == i || bottoms[j] == i) {
                    if (tops[j] == i) {
                        curSwapsBot++;
                    }
                    if (bottoms[j] == i) {
                        curSwapsTop++;
                    }
                } else {
                    curSwapsTop = INT_MAX;
                    curSwapsBot = INT_MAX;
                    break;
                }
            }
            minSwaps = min(minSwaps, min(curSwapsBot, curSwapsTop));
            // cout << i << " " << minSwaps << endl;
            // cout << curSwapsBot << " " << curSwapsTop << endl;
        }
        return minSwaps == INT_MAX ? -1 : minSwaps;
    }
};