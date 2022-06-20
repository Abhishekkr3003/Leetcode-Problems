class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        if(nums.size()==1) return {nums[0][0],nums[0][0]};
        
        vector<int>ptrs(nums.size(),0);
        set<pair<int,int>>st;
        
        for(int i=0;i<nums.size();i++){
            st.insert({nums[i][ptrs[i]],i});
            ptrs[i]++;
        }
        vector<int>res={st.begin()->first, prev(st.end())->first};
        int diff=prev(st.end())->first-st.begin()->first;
        while(ptrs[st.begin()->second]<nums[st.begin()->second].size()){
            int frontIdx=st.begin()->second;
            st.erase(st.begin());
            st.insert({nums[frontIdx][ptrs[frontIdx]],frontIdx});
            ptrs[frontIdx]++;
            if(diff>prev(st.end())->first-st.begin()->first){
                diff=prev(st.end())->first-st.begin()->first;
                res={st.begin()->first, prev(st.end())->first};
            }
        }
        return res;
    }
};