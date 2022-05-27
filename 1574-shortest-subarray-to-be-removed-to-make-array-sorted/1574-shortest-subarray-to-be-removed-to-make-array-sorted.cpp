/* 
    Time: O(nlogn)
    Space: O(n)
    Tag: Binary Search (Can be done on O(n) time and O(1) Space in similar way using https://leetcode.com/problems/shortest-subarray-to-be-removed-to-make-array-sorted/discuss/830480/C%2B%2B-O(N)-Sliding-window-Explanation-with-Illustrations)
    Difficulty: M
*/

class Solution {
public:
    int findLengthOfShortestSubarray(vector<int> &arr) {
        int n = arr.size();
        vector<int> reachLeftEnd;
        reachLeftEnd.push_back(arr[0]);
        for (int i = 1; i < n; i++) {
            if (arr[i] >= arr[i - 1])
                reachLeftEnd.push_back(arr[i]);
            else
                break;
        }
        int res = n - reachLeftEnd.size();
        // cout<<res<<endl;
        for (int i = n - 1; i >= 0; i--) {
            if (i==n-1 || (i != n - 1 && arr[i] <= arr[i + 1])) {
                int index = upper_bound(reachLeftEnd.begin(), reachLeftEnd.end(), arr[i]) - reachLeftEnd.begin();
                res = min(res, i - index);
            } else {
                break;
            }
            // cout<<res<<endl;
        }
        return max(res,0);
    }
};