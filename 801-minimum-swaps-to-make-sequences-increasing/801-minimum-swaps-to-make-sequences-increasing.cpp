class Solution {
    vector<vector<int>> t;
    vector<int> nums1, nums2;

    int findMinSwaps(int index, bool isSwaped) {
        // cout<<index<<endl;
        if (index == nums1.size()) return 0;
        int res = INT_MAX;
        if (nums1[index] > nums2[index - 1] && nums1[index - 1] < nums2[index]) {
            if (t[index][0] != -1)
                res = min(res, t[index][0]);
            else {
                swap(nums1[index], nums2[index]);
                int temp = findMinSwaps(index + 1, true);
                if (temp != INT_MAX)
                    res = min(res, 1 + temp);
                swap(nums1[index], nums2[index]);
                t[index][0] = 1 + temp;
            }
        }
        if (nums1[index] > nums1[index - 1] && nums2[index] > nums2[index - 1]) {
            if (t[index][1] != -1)
                res = min(res, t[index][1]);
            else {
                int temp = findMinSwaps(index + 1, false);
                if (temp != INT_MAX)
                    res = min(res, temp);
                t[index][1] = temp;
            }
        }
        return res;
    }

public:
    int minSwap(vector<int> &nums1, vector<int> &nums2) {
        t.resize(nums1.size()+1, vector<int>(2, -1));
        this->nums1 = nums1;
        this->nums2 = nums2;
        int res = findMinSwaps(1, false);
        // cout<<res<<endl;
        swap(this->nums1[0], this->nums2[0]);
        int temp = findMinSwaps(1, true);
        if (temp != INT_MAX)
            res = min(res, 1 + temp);
        swap(this->nums1[0], this->nums2[0]);
        return res;
    }
};