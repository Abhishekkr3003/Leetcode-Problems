class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int res=0;
        unordered_map<int,int>mp;
        for(int num:time){
            res+=mp[(60-num%60)];
            mp[num%60]++;
        }
        return res+((long long)mp[0]*(mp[0]-1))/2;
    }
};