typedef long long ll;

/* 
    Time: O()
    Space: O()
    Tag: 
    Difficulty: 
*/

class Solution {
public:
    long long wonderfulSubstrings(string word) {
        ll res = 0;
        unordered_map<int, int> freq;
        freq[0] = 1;
        int xor_ = 0;
        for (char &ch : word) {
            xor_ = xor_ ^ (1<<(ch - 'a'));
            res+=freq[xor_];
            for (int i = 0; i < 10; i++) {
                res += freq[xor_ ^ (1<<i)];
            }
            // cout<<res<<endl;
            freq[xor_]++;
        }
        return res;
    }
};