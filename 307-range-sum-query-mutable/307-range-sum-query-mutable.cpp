/* 
    Time: O(n) Build | O(log(n)) Query | O(log(n)) Update
    Space: O(n)
    Tag: Segment Tree
    Difficulty: M
*/

class NumArray {
    vector<int> tree;
    int n;

    void buildTree(int lo, int hi, vector<int> &nums, int index) {
        if (lo == hi) {
            tree[index] = nums[lo];
            return;
        }
        int mid = lo + (hi - lo) / 2;
        buildTree(lo, mid, nums, 2 * index);
        buildTree(mid + 1, hi, nums, 2 * index + 1);
        tree[index] = tree[2 * index] + tree[2 * index + 1];
    }

public:
    NumArray(vector<int> &nums) {
        n = nums.size();
        tree.resize(n * 4 + 1);
        buildTree(0, n - 1, nums, 1);
    }

    void updateRange(int lo, int hi, int index, int val, int pos) {
        if (pos > hi || pos < lo) return;
        if (lo == hi) {
            tree[index] = val;
            return;
        }
        
        int mid = lo + (hi - lo) / 2;
        updateRange(lo, mid, 2 * index, val, pos);
        updateRange(mid + 1, hi, 2 * index + 1, val, pos);
        tree[index] = tree[2 * index] + tree[2 * index + 1];
    }
    void update(int index, int val) {
        updateRange(0, n - 1, 1, val, index);
    }

    int query(int qs, int qe, int lo, int hi, int index) {
        if (qs > hi || qe < lo) return 0;
        if (lo >= qs && hi <= qe) return tree[index];
        int mid = lo + (hi - lo) / 2;
        int left = query(qs, qe, lo, mid, 2 * index);
        int right = query(qs, qe, mid + 1, hi, 2 * index + 1);
        return left + right;
    }
    int sumRange(int left, int right) {
        return query(left, right, 0, n - 1, 1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */