// MH | Monotonic Stack (nsl, nsr) | T: O(n) | S:O(n)

class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
       stack<pair<long long, long long>> st;
        vector<long long> nsr(nums.size());
        vector<long long> nsl(nums.size());
        vector<long long> prefix(nums.size() + 1);
        prefix[0] = 0;
        for (int i = 0; i < nums.size(); i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        for (int i = 0; i < nums.size(); i++) {
            while (!st.empty() && st.top().second >= nums[i]) st.pop();
            if (st.empty())
                nsl[i] = 0;
            else
                nsl[i] = st.top().first + 1;
            st.push({i,nums[i]});
        }
        while (!st.empty()) st.pop();
        
        for (int i = nums.size() - 1; i >= 0; i--) {
            while (!st.empty() && st.top().second >= nums[i]) st.pop();
            if (st.empty())
                nsr[i] = nums.size();
            else
                nsr[i] = st.top().first;
            st.push({i,nums[i]});
        }
        
        long long res = 0;
        for (int i = 0; i < nums.size();i++){
            // cout<<prefix[nsr[i]]<<" "<<prefix[nsl[i]]<<" "<<nums[i]<<endl;
            res = max(res,nums[i] * (prefix[nsr[i]] - prefix[nsl[i]]));
        }
        int mod=1e9+7;
        int ans=res%mod;
        return ans;
    }
};