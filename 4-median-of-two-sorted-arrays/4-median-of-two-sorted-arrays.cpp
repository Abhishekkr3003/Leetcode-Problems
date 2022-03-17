/* 
    Time: O(log(m+n))
    Space: O(1)
    Tag: Binary Search
    Difficulty: H
*/

class Solution {
public:
    double findMedianSortedArrays(vector<int> &X, vector<int> &Y) {
        if (X.size() > Y.size()) return findMedianSortedArrays(Y,X);
        int x = X.size(), y = Y.size();
        if (x == 0) {
            return ((y & 1) ? Y[y / 2] : (Y[y / 2] + Y[y / 2 - 1]) / 2.0);
        } else if (y == 0) {
            return ((x & 1) ? X[x / 2] : (X[x / 2] + X[(x / 2) -1]) / 2.0);
        }

        int lo = 0, hi = x;
        int x1, x2, y1, y2;
        int mid, partition =( x + y) / 2;
        while (lo <= hi) {
            mid = lo + (hi - lo) / 2;
            if (mid == x || mid == 0) {
                if (mid == 0) {
                    x1 = INT_MIN;
                    x2 = X[0];
                }
                if (mid == x) {
                    x1 = X.back();
                    x2 = INT_MAX;
                }
            } else {
                x1 = X[mid - 1];
                x2 = X[mid];
            }
            if (partition - mid == 0 || partition - mid == y) {
                if (partition - mid == 0) {
                    y1 = INT_MIN;
                    y2 = Y[0];
                }

                if (partition - mid == y) {
                    y1 = Y.back();
                    y2 = INT_MAX;
                }
            } else {
                y1 = Y[partition - mid - 1];
                y2 = Y[partition - mid];
            }
            // cout<<mid<<" "<<partition-mid<<" "<<x1<<" "<<x2<<" "<<y1<<" "<<y2<<endl;
            if (x1 <= y2 && y1 <= x2)
                return (((x + y) & 1) ? min(x2, y2) : (max(x1, y1) + min(x2, y2)) / 2.0);
            else if (x1 > y2)
                hi = mid - 1;
            else
                lo = mid + 1;
        }
        return -1;
    }
};