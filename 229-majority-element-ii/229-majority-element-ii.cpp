class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        if(nums.size()==1) return {nums[0]};
            
        int cand1=0;
        int cand2=1;
        int votes1=0, votes2=0;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]==cand1) votes1++;
            else if(nums[i]==cand2) votes2++;
            else if(votes1==0) cand1=nums[i], votes1=1;
            else if(votes2==0) cand2=nums[i], votes2=1;
            else votes1--, votes2--;
        }
        // cout<<cand1<<" "<<cand2<<endl;
        vector<int>res;
        
        int count1=0, count2=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==cand1) count1++;
            else if(nums[i]==cand2) count2++;
        }
        if(count1>nums.size()/3) res.push_back(cand1);
        if(count2>nums.size()/3) res.push_back(cand2);
        return res;
    }
};