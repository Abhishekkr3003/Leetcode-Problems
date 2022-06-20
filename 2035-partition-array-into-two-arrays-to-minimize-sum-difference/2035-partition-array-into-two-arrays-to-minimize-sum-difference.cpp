class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        
        int totalSum=0;
        int n=nums.size();
        vector<int>part1(n/2), part2(n/2);
        
        for(int i=0;i<n/2;i++){
            part1[i]=nums[i];
            totalSum+=nums[i];
        }
        for(int i=n/2;i<n;i++){
            part2[i-n/2]=nums[i];
            totalSum+=nums[i];
        }
        
        int m=part1.size();
        unordered_map<int, vector<int>>mp;
        
        for(int i=0;i<(1<<m);i++){
            int count=0;
            int sum=0;
            for(int j=0;j<m;j++){
                if(i&(1<<j)){
                    count++;
                    sum+=part1[j];
                }
            }
            mp[count].push_back(sum);
        }
        
        for(auto it=mp.begin();it!=mp.end();it++) sort(it->second.begin(),it->second.end());
        
        int res=INT_MAX;
        
        for(int i=0;i<(1<<m);i++){
            int count=0;
            int sum=0;
            for(int j=0;j<m;j++){
                if(i&(1<<j)){
                    count++;
                    sum+=part2[j];
                }
            }
            auto it=lower_bound(mp[m-count].begin(), mp[m-count].end(), totalSum/2-sum);
            
            if(it!=mp[m-count].end()){
                res=min(res,abs(totalSum-2*(sum+*it)));
            }
        }
        return res;       
    }
};