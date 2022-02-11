class Solution {
    vector<int>res;
    
    void merge(vector<pair<int,int>>&nums, int start, int end, int mid){
        // cout<<"start-";
        int i=start, j=mid+1;
        vector<pair<int,int>>temp;
        int count=0;
        while(i<=mid && j<=end){
            if(nums[i].first<=nums[j].first) {
                res[nums[i].second]+=count;
                temp.push_back(nums[i++]);
            }
            else{
                count++;
                temp.push_back(nums[j++]);
            }
        }
        while(i<=mid){
            res[nums[i].second]+=count;
            temp.push_back(nums[i++]);
        }
        while(j<=end){
            temp.push_back(nums[j++]);
        }
        j=0;
        for(i=start;i<=end;i++) nums[i]=temp[j++];
        // cout<<"end;\n";
    }
    
    void divideAndCon(vector<pair<int,int>>&nums, int i, int j){
        if(i>=j) return;
        int mid=i+(j-i)/2;
        divideAndCon(nums,i,mid);
        divideAndCon(nums,mid+1,j);
        return merge(nums,i,j,mid);
    }
public:
    vector<int> countSmaller(vector<int>& nums) {
        res.resize(nums.size(),0);
        vector<pair<int,int>>temp(nums.size());
        for(int i=0;i<nums.size();i++) temp[i]={nums[i],i};
        divideAndCon(temp,0,nums.size()-1);
        return res;
    }
};