class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long reachable=0;
        int ptr=0;
        int extra=0;
        while(reachable<n){
            // cout<<reachable<<" "<<ptr<<endl;
            while(ptr<nums.size() && nums[ptr]<=reachable+1){
                
                reachable=max(reachable,nums[ptr++]+reachable);
                // cout<<"Val: "<<reachable<<" "<<ptr<<endl;
            }
            // cout<<"here";
            // cout<<reachable<<" "<<ptr<<endl;
            if(reachable<n && (ptr>=nums.size() || reachable<nums[ptr]-1)){
                extra++;
                reachable+=(reachable+1);
            }
        }
        return extra;
    }
};