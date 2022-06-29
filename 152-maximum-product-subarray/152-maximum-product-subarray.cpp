class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int pos=0, neg=0;
        int res=INT_MIN;
        
        if(nums.size()==1) return nums[0];
        
        for(int num:nums){
            if(num==0) {
                pos=0,neg=0;
            }
            else if(num>0) {
                if(pos==0) pos=1;
                pos*=num, neg*=num;
            }
            else{
                int temp=pos;
                if(temp==0) temp=1;
                pos=max(0,neg*num);
                neg=temp*num;
            }
            res=max(res,pos);
        }
        
        return res;
    }
};