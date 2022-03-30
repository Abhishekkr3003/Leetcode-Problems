/*
    Time: O(nlogn)
    Space: O(1)
    Tag: Sorting, Greedy
    Difficulty: E
*/

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [](auto &a, auto &b){
            return a[1]>b[1];
        });
        int res=0, i=0;
        while(i<boxTypes.size() && truckSize){
            res+=boxTypes[i][1]*(min(truckSize, boxTypes[i][0]));
            truckSize-=min(truckSize, boxTypes[i][0]);
            i++;
        }
        return res;
    }
};