/*
    Time: O(n)  Note: QuickSelect N + N/2 + N/4 + N/8+ ... + N/N === 2N
    Space: O(1) Except for size k for giving the result
    Tag: QuickSelect
    Difficulty: M
*/

class Solution {
    int getDist(vector<int>&pt){
        return pt[0]*pt[0]+pt[1]*pt[1];
    }
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int lo=0, hi=points.size()-1;
        while(true){
            int i=lo-1;
            int pivot=getDist(points[hi]);
            for(int j=lo;j<hi;j++){
                if(getDist(points[j])<pivot){
                    swap(points[++i],points[j]);
                }
            }
            swap(points[++i],points[hi]);
            if(i+1==k) {
                break;
            }
            else if(i+1>k) {
                hi=i-1;
            }else{
                lo=i+1;
            }
        }
        return vector<vector<int>>(points.begin(), points.begin() + k);;
    }
};