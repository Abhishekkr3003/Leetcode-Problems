/* 
    Time: O()
    Space: O()
    Tag: 
    Difficulty: 
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