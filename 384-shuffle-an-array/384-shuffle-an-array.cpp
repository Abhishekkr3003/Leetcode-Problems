class Solution {
    vector<int>t;
    vector<int>orig;
public:
    Solution(vector<int>& nums) {
        orig=nums;
    }
    
    vector<int> reset() {
        return orig;
    }
    
    vector<int> shuffle() {
        t=orig;
        for(int i=0;i<orig.size();i++){
           int j=rand() %orig.size();
            swap(t[i],t[j]);
        }
        return t;        
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */