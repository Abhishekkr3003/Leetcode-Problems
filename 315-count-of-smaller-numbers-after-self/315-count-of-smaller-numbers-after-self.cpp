class Solution {
    
    vector<int>res;
    
    void merge(vector<pair<int,int>>&nums, int lo, int hi, int mid){
        int h1=lo, h2=mid+1;
        vector<pair<int,int>>temp(hi-lo+1);
        int k=0;
        
        while(h1<=mid && h2<=hi){
            if(nums[h1].first>nums[h2].first){
                res[nums[h1].second]+=hi-h2+1;
                temp[k++]=nums[h1++];
            }else{
                temp[k++]=nums[h2++];
            }
        }
        while(h1<=mid){
            temp[k++]=nums[h1++];
        }
        while(h2<=hi){
            temp[k++]=nums[h2++];
        }
        k=0;
        for(int i=lo;i<=hi;i++){
            nums[i]=temp[k++];
        }
    }
    
    void divideAndMerge(vector<pair<int,int>>&nums, int lo, int hi){
        if(lo>=hi) return;
        int mid=lo+(hi-lo)/2;
        divideAndMerge(nums,lo,mid);
        divideAndMerge(nums,mid+1,hi);
        merge(nums,lo,hi,mid);
    }
    
    
public:
    vector<int> countSmaller(vector<int>& nums) {
        res.resize(nums.size(),0);
        
        vector<pair<int,int>>t(nums.size());
        for(int i=0;i<nums.size();i++) t[i]={nums[i],i};
        
        divideAndMerge(t,0,nums.size()-1);
        return res;
    }
};