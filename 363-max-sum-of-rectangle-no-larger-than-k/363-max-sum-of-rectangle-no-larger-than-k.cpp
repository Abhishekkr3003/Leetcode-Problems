// class Solution {
// public:
//     int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
//         int m=matrix.size();
//         int n=matrix[0].size();
        
//         vector<vector<int>>t(m, vector<int>(n+1));
        
//         for(int i=0;i<m;i++){
//             for(int j=1;j<=n;j++){
//                 t[i][j]=matrix[i][j-1]+t[i][j-1];
//             }
//         }
        
//         int res=INT_MIN;
//         int sum=0;
//         for(int i=1;i<=n;i++){
//             for(int j=i-1;j>=0;j--){
                
//                 set<int>st;
//                 st.clear();
//                 st.insert(0);
//                 sum=0;
//                 // if(sum<=k) res=max(res,sum);
//                 // st.insert(sum);
                
//                 for(int k=0;k<m;k++){
//                     sum+=t[k][i]-t[k][j];
//                     cout<<sum<<endl;
//                     auto it=st.lower_bound(sum-k);
//                     cout<<"*it: "<<(*it)<<endl;
//                     if(it!=st.end()){
//                         res=max(res,sum-(*it));
//                     }
//                     st.insert(sum);
//                     cout<<"res: "<<res<<endl;
//                 }
//                 cout<<"end\n";
//             }
//             cout<<"***\n";
//         }
//         return res;
//     }
// };
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        if (matrix.empty()) return 0;
        int row = matrix.size(), col = matrix[0].size(), res = INT_MIN;
        for (int l = 0; l < col; ++l) {
            vector<int> sums(row, 0);
            for (int r = l; r < col; ++r) {
                for (int i = 0; i < row; ++i) {
                    sums[i] += matrix[i][r];
                }

                // Find the max subarray no more than K 
                set<int> accuSet;
                accuSet.insert(0);
                int curSum = 0, curMax = INT_MIN;
                for (int sum : sums) {
                    curSum += sum;
                    set<int>::iterator it = accuSet.lower_bound(curSum - k);
                    if (it != accuSet.end()) curMax = std::max(curMax, curSum - *it);
                    accuSet.insert(curSum);
                }
                res = std::max(res, curMax);
            }
        }
        return res;
    }
};
