typedef long long ll;
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        ll res=0;
        stack<vector<ll>>ns, ng;
        
        for(ll i=0;i<nums.size();i++){
            
            while(!ns.empty() && ns.top()[0]>nums[i]) ns.pop();
            while(!ng.empty() && ng.top()[0]<nums[i]) ng.pop();
            
            if(ns.empty()){
                ns.push({nums[i],i,nums[i]*(i+1)});
            }else{
                ns.push({nums[i],i,nums[i]*(i-ns.top()[1])+ns.top()[2]});
            }
            if(ng.empty()){
                ng.push({nums[i],i,nums[i]*(i+1)});
            }else{
                ng.push({nums[i],i,nums[i]*(i-ng.top()[1])+ng.top()[2]});
            }
            
            res-=ns.top()[2];
            res+=ng.top()[2];
            
        }
        return res;
    }
};