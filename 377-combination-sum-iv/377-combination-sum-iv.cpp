#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
    vector<int> t;
    vector<int> nums;
    int solve(int num) {
        if(num==0)
            return 1;
        if(t[num]!=-1)
            return t[num];
        ll temp=0;
        for (int i : nums) {
            if(num-i>=0)
                temp += solve(num-i);
        }
        return t[num] = temp;
    }

public:
    int combinationSum4(vector<int> &nums, int target) {
        t.resize(target + 1, -1);
        this->nums = nums;
        return solve(target);
    }
};