/*
    Time: O(nlogn)
    Space: O(n)
    Tag: Binary Search (UpperBound), Sorting
    Difficulty: H
    Note: Had to see the hints
*/

class Solution {
public:
    int minOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int>t;
        t.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=nums[i-1]) t.push_back(nums[i]);
        }
        int res = nums.size() - 1;
        int restNum = nums.size() - 1;
        for (int i = 0; i < nums.size(); i++) {
            int range = nums[i] + restNum;
            int inRange = restNum - (upper_bound(t.begin(), t.end(), range)-upper_bound(t.begin(), t.end(), nums[i]));
            res = min(res, inRange);
        }
        return res;
    }
};