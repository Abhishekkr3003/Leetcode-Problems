class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        if(nums.size()==1 && k%2==1) return -1;
        if(k==0) return nums[0];
        // int maxEle=-1;
        priority_queue<int,vector<int>,greater<int>>q;
        reverse(nums.begin(),nums.end());
        k--;
        if(k%2==1)
            k=min(k,(int)nums.size()+5);
        else k=min(k,(int)nums.size()+6);
        while(k--){
            if(nums.size()==0){
                nums.push_back(q.top());
                q.pop();
            }else{
                q.push(nums.back());
                nums.pop_back();
            } 
        }
        if(nums.size()==1 && q.empty())  return nums[0];
        int num=-1;
        while(!q.empty()) {
            num=q.top();
            q.pop();
        }
        // cout<<nums.back()<<endl;
        // cout<<num<<endl;
        // for(int i:nums) cout<<i<<endl;
        if(nums.empty()) return num;
        if(nums.size()==1) return num;
        nums.pop_back();
        return max(nums.back(),num);
    }
};