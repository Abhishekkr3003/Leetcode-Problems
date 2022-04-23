/* 
    Time: O(nlogn)
    Space: O(n)
    Tag: DP and Binary Seach (LIS)
    Difficulty: H
*/

class Solution {
public:
    int kIncreasing(vector<int> &arr, int k) {
        int res = 0;
        vector<int> lis;

        for (int i = 0; i < k; i++) {
            int size = 0;
            for (int j = i; j < arr.size(); j += k) {
                size++;
                auto it = upper_bound(lis.begin(), lis.end(), arr[j]);
                if (it == lis.end())
                    lis.push_back(arr[j]);
                else
                    *it = arr[j];
            }
            res += size - lis.size();
            lis.clear();
        }
        return res;
    }
};