// E | Sorting and Intervals | T: O(nlogn) | S: O(1)

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](vector<int>&a, vector<int>&b){
            if(a[0]==b[0]) return a[1]>b[1];
            return a[0]<b[0];
        });
        int delCount=0;
        vector<int>last=intervals[0];
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][1]<=last[1]) delCount++;
            else last=intervals[i];
        }
        return intervals.size()-delCount;
    }
};