class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int>q;
        int minEle=INT_MAX;
        for(int num:nums){
            if(num&1) {
                q.push(num*2);
                minEle=min(minEle,2*num);
            }
            else {
                q.push(num);
                minEle=min(minEle,num);
            }
        }
        int res=INT_MAX;
        while((q.top()&1)!=1){
            res=min(q.top()-minEle,res);
            int temp=q.top();
            minEle=min(minEle,temp/2);
            q.pop();
            q.push(temp/2);
        }
        res=min(q.top()-minEle,res);
        return res;
    }
};