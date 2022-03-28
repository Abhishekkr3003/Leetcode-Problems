/*
     Time: O(n) - worst case and O(log(n)) -average case
     Space: O(1)
     Tag: Binary Search
     Difficulty: H
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size() - 1;
        int mid = 0, num = 0;
        while (lo <= hi) {
            mid = lo + (hi - lo) / 2;
            if (nums[mid] == target || nums[lo] == target || nums[hi] == target) return true;
            if (nums[mid] == nums[lo] && nums[hi] == nums[mid]) { lo++, hi--;  continue; } // This is the most important condition which makes it different from search in rotated sorted array 1. ( Seen this condition from [https://leetcode.com/problems/search-in-rotated-sorted-array-ii/discuss/28218/My-8ms-C%2B%2B-solution-(o(logn)-on-average-o(n)-worst-case)])
            num=nums[mid];
            if (nums[mid] >= nums[lo] && target <= nums[lo]) num = INT_MIN;
            else if (nums[mid]<=nums[lo] && target>=nums[lo]) num = INT_MAX;

            if (num > target) hi = mid - 1;
            else lo = mid + 1;
        }
        return false;
    }
};