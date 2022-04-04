/*
    Time: O()
    Space: O()
    Tag:
    Difficulty:
*/

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<int>>q;
        int i = 0;
        for (;i < heights.size() - 1 && ladders;i++) {
            if (heights[i] < heights[i + 1]) {
                ladders--;
                q.push(heights[i + 1] - heights[i]);
            }
        }
        while (i < heights.size() - 1) {
            if (heights[i + 1] > heights[i]) {
                q.push(heights[i + 1] - heights[i]);
                if (bricks < q.top()) break;
                else bricks -= q.top();
                q.pop();
            }
            i++;
        }
        return i;
    }
};