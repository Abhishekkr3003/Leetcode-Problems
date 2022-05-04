/* 
    Time: O()
    Space: O()
    Tag: 
    Difficulty: 
*/

class Solution {
public:
    int maxOperations(vector<int> &nums, int k) {
        int res = 0;
        unordered_map<int, int> mp;
        for (int &num : nums) {
            if (mp[k - num] != 0) {
                mp[k - num]--;
                res++;
            } else
                mp[num]++;
        }
        return res;
    }
};