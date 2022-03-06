// M | Maths (Permutation from previous step) | T: O(n) | S: O(1)
// Approach: https://drive.google.com/file/d/1Vx5YT4aCFHWkXF7WmudGzAHnf7kZcAHx/view

class Solution {
public:
    int countOrders(int n) {
        long long res=1;
        int mod = 1e9 + 7;
        for (int i = 2; i <= n;i++){
            res = res * ((i*2) * ((i*2)- 1)) / 2;
            res%=mod;
        }
        return res;
    }
};