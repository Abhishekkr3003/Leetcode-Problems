
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
    Time: O(nlogn)
    Space: O(n)
    Tag: Binary Search (Upper Bound)
    Difficulty: M
    Note: Took help from https://www.youtube.com/watch?v=66w10xKzbRM
*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> lis;
        lis.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            int index = upper_bound(lis.begin(), lis.end(), nums[i]) - lis.begin();
            if (index == lis.size() && lis.back() != nums[i]) {
                lis.push_back(nums[i]);
                continue;
            }
            if (index == 0) lis[index] = nums[i];
            else if (lis[index - 1] != nums[i]) lis[index] = nums[i];
        }
        return lis.size();
    }
};