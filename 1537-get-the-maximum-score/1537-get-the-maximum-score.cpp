/*
    Time: O(nlogn) 
    Space: O(n)
    Tag: Preifx Sum, Binary Search (Lower Bound)
    Difficulty: M
    Note: Can be solved in O(n) time and O(1) space with two pointers (See Lee)
*/

class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        vector<long long>prefNums1(nums1.size() + 1), prefNums2(nums2.size() + 1);
        int mod=1e9+7;
        prefNums1[0] = 0, prefNums2[0] = 0;
        for (int i = 1; i < prefNums1.size(); i++) {
            prefNums1[i] =(prefNums1[i]+ nums1[i - 1] + prefNums1[i - 1]);
        }
        for (int i = 1; i < prefNums2.size(); i++) {
            prefNums2[i] =( prefNums2[i]+nums2[i - 1] + prefNums2[i - 1]);
        }
        int res = 0;
        int lastIdx1 = 0, lastIdx2 = 0;
        for (int i = 0; i < nums1.size(); i++)
        {
            int idx = lower_bound(nums2.begin(), nums2.end(), nums1[i]) - nums2.begin();
            if (idx >= nums2.size() || nums2[idx] != nums1[i]) continue;
            res =(res+ max(prefNums1[i + 1] - prefNums1[lastIdx1], prefNums2[idx + 1] - prefNums2[lastIdx2]))%mod;
            // cout<<idx<<endl;
            // cout<<res<<endl;
            lastIdx1 = i + 1;
            lastIdx2 = idx + 1;
        }
        res =(res+ max(prefNums1.back() - prefNums1[lastIdx1], prefNums2.back() - prefNums2[lastIdx2]))%mod;
        return res;
    }
};