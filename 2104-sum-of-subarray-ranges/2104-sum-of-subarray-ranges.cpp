/*
    Time: O()
    Space: O()
    Tag:
    Difficulty:
*/

typedef long long ll;

class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        stack<vector<ll>>NSL; //{Prev_Smallest_Val, res_till_prev_val, prev_val_index}
        stack<vector<ll>>NGL; //{Prev_Largest_Val, res_till_prev_val, prev_val_index}
        NSL.push({ INT_MIN, 0, -1 });
        NGL.push({ INT_MAX,0,-1 });
        ll res = 0;
        ll nextNSLval = 0, nextNGLval = 0;
        for (int i = 0; i < nums.size(); i++) {
            while (nums[i] <= NSL.top()[0]) NSL.pop();
            while (nums[i] >= NGL.top()[0]) NGL.pop();
            nextNGLval = nums[i] * (i - NGL.top()[2]) + NGL.top()[1];
            nextNSLval = nums[i] * (i - NSL.top()[2]) + NSL.top()[1];
            res += nextNGLval - nextNSLval;
            NGL.push({ nums[i],nextNGLval,i });
            NSL.push({ nums[i],nextNSLval,i });
        }
        return res;
    }
};