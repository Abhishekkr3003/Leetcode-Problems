class Solution {
public:
    int validSubarraySize(vector<int>& nums, int threshold) {
        vector<int>nsl(nums.size()), nsr(nums.size());
        stack<pair<int,int>>st;
        
        for(int i=0;i<nums.size();i++){
            while(!st.empty() && st.top().first>=nums[i]) st.pop();
            if(st.empty()) nsl[i]=-1;
            else nsl[i]=st.top().second;
            st.push({nums[i],i});
        }
        
        while(!st.empty()) st.pop();
        
        for(int i=nums.size()-1;i>=0;i--){
            while(!st.empty() && st.top().first>=nums[i]) st.pop();
            if(st.empty()) nsr[i]=nums.size();
            else nsr[i]=st.top().second;
            st.push({nums[i],i});
        }
        
        vector<int>t(nums.size()+1,-1);
        
        for(int i=0;i<nums.size();i++){
            t[nsr[i]-nsl[i]-1]=max(t[nsr[i]-nsl[i]-1],nums[i]);            
        }
                
        for(int i=1;i<=nums.size();i++){
            if(t[i]>(threshold/i)) return i;
        }
        return -1;
    }
};