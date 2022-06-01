class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int res=0;
        int posCount=0, negCount=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                posCount=0, negCount=0;
            }else if(nums[i]<0){
                int temp=negCount;
                negCount=posCount+1;
                posCount=temp+(temp==0?0:1);
            }else{
                posCount++;
                if(negCount>0) negCount++;
            }
            res=max(res,posCount);
        }
        return res;
    }
};