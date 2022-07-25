
/* 
    Time: O(log(n))
    Space: O(1)
    Tag: Binary Search
    Difficulty: M
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
    int bSearchMin(vector<int> nums, int target) {
        int mid, l = 0, h = nums.size() - 1;
        while (l <= h) {
            mid = (h - l) / 2 + l;
            if (nums[mid] == target && (mid == 0 || nums[mid - 1] != target)) {
                return mid;
            } else if (nums[mid] < target) {
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        }
        return -1;
    }
    int bSearchMax(vector<int> nums, int target) {
        int mid, l = 0, h = nums.size() - 1;
        while (l <= h) {
            mid = (h - l) / 2 + l;
            if (nums[mid] == target && ((mid == nums.size() - 1) || nums[mid + 1] != target)) {
                return mid;
            } else if (nums[mid] > target) {
                h = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return -1;
    }

public:
    vector<int> searchRange(vector<int> &nums, int target) {
        return {bSearchMin(nums, target), bSearchMax(nums, target)};
    }
};