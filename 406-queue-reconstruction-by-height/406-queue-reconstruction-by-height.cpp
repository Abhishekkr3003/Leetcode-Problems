class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(),[](const vector<int>&a,const vector<int>& b){
            return a[0]!=b[0]?a[0]>b[0]:a[1]<b[1];
        });
        vector<vector<int>>res;
        for(auto v:people){
            res.insert(res.begin()+v[1], v);
        }
        return res;
        
    }
};