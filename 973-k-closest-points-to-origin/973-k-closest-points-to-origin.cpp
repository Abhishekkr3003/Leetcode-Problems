class Solution {
    int getDist(vector<int>&pt){
        return pt[0]*pt[0]+pt[1]*pt[1];
    }
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>>res(k);
        int lo=0, hi=points.size()-1;
        while(true){
            // cout<<lo<<" "<<hi<<" "<<k<<endl;
            int i=lo-1;
            int pivot=getDist(points[hi]);
            for(int j=lo;j<hi;j++){
                if(getDist(points[j])<pivot){
                    swap(points[++i],points[j]);
                }
            }
            swap(points[++i],points[hi]);
            if(i+1==k) {
                // cout<<"/here";
                for(int j=0;j<=i;j++){
                    res[j]=points[j];
                }
                break;
            }
            else if(i+1>k) {
                hi=i-1;
            }else{
                lo=i+1;
            }
        }
        return res;
    }
};