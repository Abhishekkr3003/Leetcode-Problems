class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        set<int>st;
        for(int i=0;i<nums.size();i++){
            auto it=st.lower_bound(nums[i]);
            if(it!=st.end()) st.erase(it);
            st.insert(nums[i]);
            if(st.size()==3) return true; 
        }
        return false;
    }
};