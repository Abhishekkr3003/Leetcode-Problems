#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/* 
        Time: O()
        Space: O()
        Tag: 
        Difficulty: 
    */
class BookMyShow {
    vector<pair<ll, ll>> tree;
    int n;
    int m;

    void buildTree(int lo, int hi, int index, int m) {
        if (lo == hi) {
            tree[index] = {m, m};
            return;
        }
        int mid = lo + (hi - lo) / 2;
        buildTree(lo, mid, 2 * index, m);
        buildTree(mid + 1, hi, 2 * index + 1, m);
        tree[index] = {max(tree[2 * index].first, tree[2 * index + 1].first),
                       tree[2 * index].second + tree[2 * index + 1].second};
    }

public:
    BookMyShow(int n, int m) {
        tree.resize(4 * n + 1);
        this->n = n;
        this->m = m;
        buildTree(0, n - 1, 1, m);
    }

    void updateGather(int lo, int hi, int index, int maxRow, int k, vector<int> &res) {
        if (lo > maxRow) return;
        if (tree[index].first < k) return;
        if (lo == hi) {
            res = {lo, m - (int)tree[index].second};
            tree[index] = {tree[index].second - k,
                           tree[index].second - k};
            return;
        }
        int mid = lo + (hi - lo) / 2;
        if (tree[2 * index].first >= k)
            updateGather(lo, mid, 2 * index, maxRow, k, res);
        else
            updateGather(mid + 1, hi, 2 * index + 1, maxRow, k, res);
        tree[index] = {max(tree[2 * index].first, tree[2 * index + 1].first),
                       tree[2 * index].second + tree[2 * index + 1].second};
    }
    vector<int> gather(int k, int maxRow) {
        vector<int> res;
        updateGather(0, n - 1, 1, maxRow, k, res);
        return res;
    }

    ll queryScatter(int lo, int hi, int index, int maxRow) {
        if (lo > maxRow) return 0;
        if (hi <= maxRow) return tree[index].second;
        int mid = lo + (hi - lo) / 2;
        ll left = queryScatter(lo, mid, 2 * index, maxRow);
        ll right = queryScatter(mid + 1, hi, 2 * index + 1, maxRow);
        return left + right;
    }

    void updateScatter(int lo, int hi, int index, int maxRow, int k) {
        if (k <= 0) return;
        if (lo > maxRow) return;

        if (lo == hi) {
            tree[index].second -= k;
            tree[index].first = tree[index].second;
            return;
        }

        int mid = lo + (hi - lo) / 2;

        ll toPassToLeft = min((ll)k, tree[2 * index].second);
        ll toPassToRight = max(0ll, k - toPassToLeft);
        updateScatter(lo, mid, 2 * index, maxRow, toPassToLeft);
        updateScatter(mid + 1, hi, 2 * index + 1, maxRow, toPassToRight);
        tree[index] = {max(tree[2 * index].first, tree[2 * index + 1].first),
                       tree[2 * index].second + tree[2 * index + 1].second};
    }

    bool scatter(int k, int maxRow) {
        if (k > queryScatter(0, n - 1, 1, maxRow)) return false;
        updateScatter(0, n - 1, 1, maxRow, k);
        return true;
    }
};
