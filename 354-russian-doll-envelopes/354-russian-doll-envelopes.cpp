// H (To find the logic that sort width dec and height inc) | DP (LIS) | T: O(nlogn) | S: O(n)

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end(), [](vector<int>&a, vector<int>&b){
            if(a[1]==b[1]) return a[0]>b[0];
            return a[1]<b[1];
        });
        vector<int>st;
        for(int i=0;i<envelopes.size();i++){
            auto it=lower_bound(st.begin(),st.end(),envelopes[i][0]);
            if(it==st.end()) st.push_back(envelopes[i][0]);
            else *it=envelopes[i][0];
        }
        return st.size();
    }
};