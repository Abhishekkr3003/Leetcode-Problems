class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum&1) return false;
        sum/=2;
        int n=nums.size();
        vector<vector<bool>> t(n + 1, vector<bool>(sum + 1, false));

        for (int i = 0; i <= n; i++) {
            t[i][0] = true;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= sum; j++) {
                if (j >= nums[i - 1]) {
                    t[i][j] = t[i - 1][j] || t[i - 1][j - nums[i - 1]];
                } else {
                    t[i][j] = t[i - 1][j];
                }
            }
        }

//         for (int i = 0; i <= n; i++) {
//             for (int j = 0; j <= sum; j++) {
//                 cout << t[i][j] << " ";
//             }
//             cout << endl;
//         }

        return t[n][sum];
    }
};