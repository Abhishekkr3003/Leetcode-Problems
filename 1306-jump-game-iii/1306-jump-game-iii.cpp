

class Solution {
    
public:
    bool canReach(vector<int> &arr, int start) {
        if ((start < 0) || (start >= arr.size()) || (arr[start] == -1)) {
            // cout << endl;
            return false;
        }

        if (arr[start] == 0) {
            return true;
        } else {
            // cout << "arr[start]:" << arr[start] << endl;
            int temp = arr[start];
            arr[start] = -1;
            return (canReach(arr, start + temp) || canReach(arr, start - temp));
        }
    }
};