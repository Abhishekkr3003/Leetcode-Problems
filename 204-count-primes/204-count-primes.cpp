class Solution {
public:
    int countPrimes(int n) {
        if(n<2) return 0;
        
        vector<bool>nums(n,true);
        
        for(int i=2;i*i<n;i++){
            if(nums[i]){
                for(int j=i*i;j<n;j+=i){
                    nums[j]=false;
                }
            }
        }
        
        int res=0;
        for(int i=2;i<n;i++) {
            if(nums[i]) res++;
        }
        return res;
    }
};