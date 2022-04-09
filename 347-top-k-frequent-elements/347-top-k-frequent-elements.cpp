class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>unique;
        unordered_map<int,int>mp;
        for(int num:nums){
            if(mp.find(num)==mp.end()) unique.push_back(num);
            mp[num]++;
        }
        int start=0, end=unique.size()-1;
        int n=unique.size();
        // for(int num:unique)cout<<num<<" ";
        // cout<<endl;
        while(1){
            int i=-1, j=0;
            int pivot=unique[end];
            while(j<end){
                if(mp[unique[j]]<=mp[pivot]) swap(unique[j],unique[++i]);
                j++;
            }
            swap(unique[end], unique[++i]);
            if(i==n-k) return vector<int>(unique.begin()+i, unique.end());
            else if(i<n-k) start=i+1;
            else end=i-1;
            // for(int num:unique)cout<<num<<" ";
            // cout<<endl;
        }
        return {};
    }
};