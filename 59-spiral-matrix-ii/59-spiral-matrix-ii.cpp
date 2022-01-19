class Solution {
public:
    vector<vector<int>> generateMatrix(int A) {
        int cur=1;
        vector<vector<int>>res(A,vector<int>(A));
        for(int loop=0;loop<(A+1)/2;loop++){
            for(int i=loop;i<A-loop;i++) res[loop][i]=cur++;
            for(int i=loop+1;i<A-loop;i++) res[i][A-loop-1]=cur++;
            for(int i=A-loop-2;i>=loop;i--) res[A-loop-1][i]=cur++;
            for(int i=A-loop-2;i>=loop+1;i--) res[i][loop]=cur++;
        }
        return res;
    }
};