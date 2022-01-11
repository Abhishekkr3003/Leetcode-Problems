/* 
    Time: O()
    Space: O()
    Tag: 
    Difficulty: 
*/

class Solution {
    vector<int> bloomDay;
    int k;
    int m;
    bool canForm(int daysPassed) {
        int curBqSize = 0;
        int count = 0;
        for (int i = 0; i < bloomDay.size(); i++) {
            if (bloomDay[i] <= daysPassed)
                curBqSize++;
            else
                curBqSize = 0;
            if (curBqSize == k)
                count++, curBqSize = 0;
        }
        return count >= m;
    }

public:
    int minDays(vector<int> &bloomDay, int m, int k) {
        int lo = *min_element(bloomDay.begin(), bloomDay.end()), hi = *max_element(bloomDay.begin(), bloomDay.end());
        int mid, ans = -1;
        this->bloomDay = bloomDay;
        this->m = m;
        this->k = k;
        while (lo <= hi) {
            mid = lo + ((hi - lo) >> 1);
            if (canForm(mid))
                ans = mid, hi = mid - 1;
            else
                lo = mid + 1;
        }
        return ans;
    }
};