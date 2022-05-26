/* 
    Time: O(n)
    Space: O(n)
    Tag: DP, Hash the last of first and find according to the second's start
    Difficulty: H
*/

class Solution {
public:
    int minSumOfLengths(vector<int> &arr, int target) {
        int res = INT_MAX;
        vector<int> t(arr.size(), INT_MAX);
        int lo = 0;
        int curSum = 0;
        for (int i = 0; i < arr.size(); i++) {
            curSum += arr[i];
            while (curSum > target) {
                curSum -= arr[lo++];
            }
            if (curSum == target) t[i] = i - lo + 1;
            if(i>0) t[i]=min(t[i],t[i-1]);
        }
        curSum = 0;
        lo=0;
        for (int i = 0; i < arr.size(); i++) {
            curSum += arr[i];
            while (curSum > target) {
                curSum -= arr[lo++];
            }
            if (curSum == target && lo != 0 && t[lo - 1] != INT_MAX) res = min(res, t[lo - 1] + i - lo + 1);
        }
        return res == INT_MAX ? -1 : res;
    }
};