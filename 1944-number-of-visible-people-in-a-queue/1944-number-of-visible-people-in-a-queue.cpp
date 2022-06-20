class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        stack<pair<int,int>>st;
        vector<int>res(heights.size(),0);
        
        for(int i=0;i<heights.size();i++){
            while(!st.empty() && st.top().first<=heights[i]) {
                res[st.top().second]++;
                st.pop();
            }
            if(!st.empty()) res[st.top().second]++;
            st.push({heights[i],i});
        }
        return res;
    }
};