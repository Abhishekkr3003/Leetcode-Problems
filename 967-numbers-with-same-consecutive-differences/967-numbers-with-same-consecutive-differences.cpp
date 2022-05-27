/* 
    Time: O()
    Space: O()
    Tag: 
    Difficulty: 
*/

class Solution {
    vector<int> res;

    void solve(int n, int k, int num) {
        // cout<<num<<endl;
        if (n == 0) {
            res.push_back(num);
            return;
        }
        int last = num % 10;
        if ((abs((last + k) % 10 - last)) == k) solve(n - 1, k, num * 10 + (last + k) % 10);
        if(num * 10 + (last + k) % 10!=num * 10 + (last - k+10) % 10)
            if ((abs((last - k+10) % 10 - last)) == k) solve(n - 1, k, num * 10 + (last - k+10) % 10);
    }

public:
    vector<int> numsSameConsecDiff(int n, int k) {
        for (int i = 1; i < 10; i++) {
            solve(n - 1, k, i);
        }
        return res;
    }
};