
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/* 
    Time: O(n)
    Space: O(n)
    Tag: DP - Fibonacci Pattern
    Difficulty: M
*/

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if (nums.size() < 3) return 0;
        vector<int> t(nums.size());
        t[0] = t[1] = 0;
        int res = 0;
        for (int i = 2; i < nums.size(); i++) {
            if(nums[i]-nums[i-1]==nums[i-1]-nums[i-2]){
                t[i] = 1 + t[i - 1];
            }
            res += t[i];
        }
        return res;
    }
};