/* 
    Time: O(nlogn) || We can apply count sort instead to reduce complexity to O(n)
    Space: O(1)
    Tag: Sorting
    Difficulty: M
*/

class Solution {
public:
    int hIndex(vector<int> &citations) {
        sort(citations.rbegin(), citations.rend());
        for (int i = 0; i < citations.size() - 1; i++) {
            if (i + 1 <= citations[i] && citations[i + 1] <= i + 1) return i + 1;
        }
        if (citations.size() <= citations.back()) return citations.size();
        return 0;
    }
};